// Fill out your copyright notice in the Description page of Project Settings.

#include "CreateObject.h"

UObject  *UCreateObject::CreaeObject(UObject *owner, UClass  *uclass)
{
	return NewObject<UObject>(owner, uclass);
}
