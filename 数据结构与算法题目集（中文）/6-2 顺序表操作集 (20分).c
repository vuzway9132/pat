List MakeEmpty() {
	List L = (List) malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}
Position Find(List L, ElementType X) {
	Position Pos = 0;
	if (L->Last == -1) return ERROR;
	while (Pos<=L->Last && L->Data[Pos]!=X)
		Pos++;
	if (Pos > L->Last) return ERROR;
	else return Pos;
}
bool Insert(List L, ElementType X, Position P) {
	if (L->Last == MAXSIZE-1) {
		printf("FULL");
		return false;
	}
	if (P < 0 || P > L->Last+1) {
		printf("ILLEGAL POSITION");
		return false;
	}
	for (int i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i];
	L->Data[P] = X;
	L->Last++;
	return true;
}
bool Delete(List L, Position P) {
	if (P < 0 || P > L->Last) {
		printf("POSITION %d EMPTY", P);
		return false;
	}
	for (int i = P; i <= L->Last-1; i++)
		L->Data[i] = L->Data[i+1];
	L->Last--;
	return true;
}
