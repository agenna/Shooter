// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// called for forward/backward movement
	void MoveForward(float Value);

	// called for right/left movement
	void MoveRight(float Value);

	//called via input to turn at a given rate 
	//@param Rate this is a normalized rate, i.e. means 100% of desired turn rate
	void TurnRate(float Rate);

	//called via input to turn at a given rate 
	//@param Rate this is a normalized rate, i.e. means 100% of desired turn rate
	void LookUpRate(float Rate);

	// function called when fire button is pressed
	void FireWeapon();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/* Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/* Camera that follows the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/* Base turn rate, in deg/sec. Other scaling may affect final turn rate */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/* Base turn rate, in deg/sec. Other scaling may affect final turn rate*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

public:
	/* returns the camera boom sub object*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const {return CameraBoom ;	}
	/* returns follow camera sub object*/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
