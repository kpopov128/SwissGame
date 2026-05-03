$ErrorActionPreference = "Stop"

function Ensure-Dir {
    param([string]$Path)

    if (!(Test-Path $Path)) {
        New-Item -ItemType Directory -Path $Path -Force | Out-Null
    }
}

function Move-IfExists {
    param(
        [string]$From,
        [string]$To
    )

    if (Test-Path $From) {
        Ensure-Dir (Split-Path $To)
        Move-Item -Path $From -Destination $To -Force
        Write-Host "Moved: $From -> $To"
    }
}

function Replace-InFile {
    param(
        [string]$Path,
        [string]$Old,
        [string]$New
    )

    if (Test-Path $Path) {
        $Content = Get-Content $Path -Raw
        $Content = $Content.Replace($Old, $New)
        Set-Content -Path $Path -Value $Content -Encoding UTF8
        Write-Host "Updated: $Path"
    }
}

Ensure-Dir "src\model\betting_field"
Ensure-Dir "src\model\betting_table"
Ensure-Dir "src\model\chip"
Ensure-Dir "src\model\game_state"

Move-IfExists "src\model\BettingField.hpp" "src\model\betting_field\BettingField.hpp"
Move-IfExists "src\model\BettingField.cpp" "src\model\betting_field\BettingField.cpp"
Move-IfExists "src\model\resources\BettingFieldResources.hpp" "src\model\betting_field\BettingFieldResources.hpp"

Move-IfExists "src\model\BettingTable.hpp" "src\model\betting_table\BettingTable.hpp"
Move-IfExists "src\model\BettingTable.cpp" "src\model\betting_table\BettingTable.cpp"
Move-IfExists "src\model\resources\BettingTableResources.hpp" "src\model\betting_table\BettingTableResources.hpp"

Move-IfExists "src\model\Chip.hpp" "src\model\chip\Chip.hpp"
Move-IfExists "src\model\Chip.cpp" "src\model\chip\Chip.cpp"
Move-IfExists "src\model\resources\ChipResources.hpp" "src\model\chip\ChipResources.hpp"

Move-IfExists "src\model\GameState.hpp" "src\model\game_state\GameState.hpp"
Move-IfExists "src\model\resources\GameResources.hpp" "src\model\game_state\GameResources.hpp"

# Remove old empty resources dir if empty
if (Test-Path "src\model\resources") {
    $Items = Get-ChildItem "src\model\resources"
    if ($Items.Count -eq 0) {
        Remove-Item "src\model\resources" -Force
        Write-Host "Removed empty: src\model\resources"
    }
}

# Fix includes across whole src
$Files = Get-ChildItem "src" -Recurse -Include *.hpp,*.cpp,*.h

foreach ($File in $Files) {
    Replace-InFile $File.FullName '#include "model/GameState.hpp"' '#include "model/game_state/GameState.hpp"'
    Replace-InFile $File.FullName '#include "model/BettingTable.hpp"' '#include "model/betting_table/BettingTable.hpp"'
    Replace-InFile $File.FullName '#include "model/BettingField.hpp"' '#include "model/betting_field/BettingField.hpp"'
    Replace-InFile $File.FullName '#include "model/Chip.hpp"' '#include "model/chip/Chip.hpp"'

    Replace-InFile $File.FullName '#include "BettingTable.hpp"' '#include "model/betting_table/BettingTable.hpp"'
    Replace-InFile $File.FullName '#include "BettingField.hpp"' '#include "model/betting_field/BettingField.hpp"'
    Replace-InFile $File.FullName '#include "Chip.hpp"' '#include "model/chip/Chip.hpp"'

    Replace-InFile $File.FullName '#include "model/resources/BettingFieldResources.hpp"' '#include "model/betting_field/BettingFieldResources.hpp"'
    Replace-InFile $File.FullName '#include "model/resources/BettingTableResources.hpp"' '#include "model/betting_table/BettingTableResources.hpp"'
    Replace-InFile $File.FullName '#include "model/resources/ChipResources.hpp"' '#include "model/chip/ChipResources.hpp"'
    Replace-InFile $File.FullName '#include "model/resources/GameResources.hpp"' '#include "model/game_state/GameResources.hpp"'
}

# Fix includes inside moved cpp files to use local headers
Replace-InFile "src\model\betting_field\BettingField.cpp" '#include "model/betting_field/BettingField.hpp"' '#include "BettingField.hpp"'
Replace-InFile "src\model\betting_table\BettingTable.cpp" '#include "model/betting_table/BettingTable.hpp"' '#include "BettingTable.hpp"'
Replace-InFile "src\model\chip\Chip.cpp" '#include "model/chip/Chip.hpp"' '#include "Chip.hpp"'

# Fix internal model dependencies
Replace-InFile "src\model\betting_field\BettingField.hpp" '#include "model/chip/Chip.hpp"' '#include "model/chip/Chip.hpp"'
Replace-InFile "src\model\betting_table\BettingTable.hpp" '#include "model/betting_field/BettingField.hpp"' '#include "model/betting_field/BettingField.hpp"'
Replace-InFile "src\model\game_state\GameState.hpp" '#include "model/betting_table/BettingTable.hpp"' '#include "model/betting_table/BettingTable.hpp"'

Write-Host ""
Write-Host "Model reorganization done."
Write-Host "Now run Clean/Rebuild in Visual Studio."