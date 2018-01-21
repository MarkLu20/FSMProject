// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMStateBase.h"
#include "FSMFunction.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSM_API UFSMFunction : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFSMFunction();
	int InvlidIndex = -1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		bool AddState(UFSMStateBase* pState);
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		void RemoveState(int stateIndex);
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		void RemoveAllState();
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		UFSMStateBase *Getstate(int stateIndex);
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		UFSMStateBase *GetCurState();
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		UFSMStateBase *GetPreState();
	UFUNCTION(BlueprintCallable, Category = "FSMFunction")
		bool ChangeState(int stateIndex);
	
protected:
	TMap<int32, UFSMStateBase*> StatesMap;
	UFSMStateBase *pCurrentState;
	UFSMStateBase *pPreState;



};
