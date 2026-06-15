// CharacterData.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterData.generated.h"

UCLASS()
class TEMPORARY_API UCharacterData : public UObject
{
	GENERATED_BODY()

public:
	UCharacterData();

	// 데이터 속성 추가
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;
};