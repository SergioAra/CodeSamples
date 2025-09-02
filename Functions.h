USTRUCT(BlueprintType)
struct FGridData
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CellIndex = -1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FBox Cell;

	FGridData()
	{
		Cell = FBox();
	}

	FGridData(const FVector& InCellLocation, const FVector& InCellExtent)
	{
		Cell = FBox(InCellLocation - InCellExtent, InCellLocation + InCellExtent);
	}
};

UFUNCTION(BlueprintCallable)
static void GenerateGrid(const FVector& GridLocation, const FVector& GridExtent, int32 XDivisions, int32 YDivisions, TArray<FGridData>& OutGridCells);
