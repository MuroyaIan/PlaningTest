// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

#include "Materials/MaterialInstance.h"

void UMyBlueprintFunctionLibrary::SetMaterialInstanceStaticSwitchParameterValue(UMaterialInstance* Instance, FName ParameterName, bool Value)
{
	FStaticParameterSet StaticParameters = Instance->GetStaticParameters();
	for (auto& SwitchParameter : StaticParameters.StaticSwitchParameters)
	{
		if (SwitchParameter.ParameterInfo.Name == ParameterName)
		{
			SwitchParameter.Value = Value;
			break;;
		}
	}
	Instance->UpdateStaticPermutation(StaticParameters);
}
