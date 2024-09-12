#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterState.generated.h"

UENUM(BlueprintType) // BlueprintType을 사용하면 블루프린트에서도 사용 가능
enum class EMonsterState : uint8
{
    Idle UMETA(DisplayName = "Idle"),
    Move UMETA(DisplayName = "Move"),
    Check UMETA(DisplayName = "Check"),
    Find UMETA(DisplayName = "Find"),
    NotFind UMETA(DisplayName = "NotFind")
};