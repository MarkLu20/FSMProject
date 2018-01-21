// Fill out your copyright notice in the Description page of Project Settings.

#include "FSMFunction.h"


// Sets default values for this component's properties
UFSMFunction::UFSMFunction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	pCurrentState = NULL;
	pPreState = NULL;

	// ...
}


// Called when the game starts
void UFSMFunction::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UFSMFunction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (pCurrentState != NULL)
	{
		pCurrentState->OnUpDate(DeltaTime);
	}


	// ...
}

bool UFSMFunction::AddState(UFSMStateBase * pState)
{
	if (pState->GetIndex() == InvlidIndex)
	{
		return false;
	}
	int stateIndex = pState->GetIndex();
	if (StatesMap.Find(stateIndex) != NULL)
	{
		return false;
	}
	StatesMap.Add(pState->GetIndex(), pState);
	return true;
}

void UFSMFunction::RemoveState(int stateIndex)
{
}

void UFSMFunction::RemoveAllState()
{
}

UFSMStateBase * UFSMFunction::Getstate(int stateIndex)

{
	if (stateIndex==InvlidIndex)
	{
		return NULL;
	}
	UFSMStateBase **pState = StatesMap.Find(stateIndex);
	if (*pState==NULL)
	{
		return NULL;
	}
	return *pState;
}

UFSMStateBase * UFSMFunction::GetCurState()
{
	return pCurrentState;
}

UFSMStateBase * UFSMFunction::GetPreState()
{
	return pPreState;
}

bool UFSMFunction::ChangeState(int stateIndex)
{
	if (pCurrentState)
	{
		if (pCurrentState->GetIndex() == stateIndex)
		{
			return false;
		}
		else
			pCurrentState->Exit();

	}
	pPreState = pCurrentState;
	if (stateIndex==InvlidIndex)
	{
		pCurrentState = NULL;
	}
	else
	{
		pCurrentState = Getstate(stateIndex);
	}
	if (pCurrentState)
	{
		pCurrentState->Enter();
	}
	else
	{
		return false;
	}
	return true;
}

