#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterState.generated.h"

UENUM(BlueprintType) // BlueprintType�� ����ϸ� �������Ʈ������ ��� ����
enum class EMonsterState : uint8
{
    Idle UMETA(DisplayName = "Idle"),
    Move UMETA(DisplayName = "Move"),
    Check UMETA(DisplayName = "Check"),
    Find UMETA(DisplayName = "Find"),
    NotFind UMETA(DisplayName = "NotFind")
};