void UHBFunctionLibrary::GenerateGrid(const FVector& GridLocation, const FVector& GridExtent, int32 XDivisions, int32 YDivisions, TArray<FGridData>& OutGridCells)
{
	if (XDivisions <= 0 || YDivisions <= 0)
	{
		DEBUG_MESSAGE_DANGER(true, 10.f, FColor::Red, "Warning: Triend to generate Grid cells with invalid divisions")
		return;
	}

	const float CellLenX = GridExtent.X * 2.f / XDivisions;
	const float CellLenY = GridExtent.Y * 2.f / YDivisions;

	const float XOffset = GridLocation.X - (GridExtent.X * (XDivisions + 1.f) / XDivisions);
	const float YOffset = GridLocation.Y - (GridExtent.Y * (YDivisions + 1.f) / YDivisions);

	const FVector OutGridExtent = FVector(CellLenX / 2.f, CellLenY / 2.f, GridExtent.Z);

	for (int32 i = 0; i < XDivisions; i++)
	{
		for (int32 j = 0; j < YDivisions; j++)
		{
			FVector OutGridLocation = FVector::ZeroVector;
			OutGridLocation.X = CellLenX * (i + 1) + XOffset;
			OutGridLocation.Y = CellLenY * (j + 1) + YOffset;
			OutGridLocation.Z = GridLocation.Z;
			
			OutGridCells.Add(FGridData(OutGridLocation, OutGridExtent));
		}
	}
}
