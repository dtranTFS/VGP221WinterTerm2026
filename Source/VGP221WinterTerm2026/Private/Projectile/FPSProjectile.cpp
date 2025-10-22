// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(15.0f);
		CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnWhateverWeWantToNameThis);
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMeshComponent) {
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));

		// 1. Setup an imported mesh
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/Meshes/Projectile/Sphere.Sphere"));

		// 2. Get assets from unreal engine
		//static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));

		if (ProjectileMeshAsset.Succeeded()) {
			ProjectileMeshComponent->SetStaticMesh(ProjectileMeshAsset.Object);
		}

		// Settings up material for sphere
		static ConstructorHelpers::FObjectFinder<UMaterial> ProjectileMaterialAsset(TEXT("/Game/Materials/Projectile/M_Projectile.M_Projectile"));
		if (ProjectileMaterialAsset.Succeeded()) {
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(ProjectileMaterialAsset.Object, ProjectileMaterialInstance);
		}

		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
		ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMeshComponent->SetupAttachment(RootComponent);
	}

	if (!ProjectileMovementComponent) {
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = BulletSpeed;
		ProjectileMovementComponent->MaxSpeed = BulletSpeed;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	InitialLifeSpan = 3.0f; // Unity Destroy(3.0f)
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	// 1. FVector ShootDirection: Pass by value, least efficient, Basically just duplicating the data and giving it to you
	// 2. FVector* ShootDirection: Pass pointer memory, efficient cus memory address. But need to dereference the pointer to get the value
	// 3. FVector& ShootDirection: Pass by reference, efficient and easy to use. Just like a normal variable or think of it as a out 
	// 4. const FVector& ShootDirection: Pass by reference but read only, efficient and safe to use

	ProjectileMovementComponent->Velocity = ProjectileMovementComponent->InitialSpeed * ShootDirection;
}

void AFPSProjectile::OnWhateverWeWantToNameThis(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()) {
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		Destroy();
	}
}