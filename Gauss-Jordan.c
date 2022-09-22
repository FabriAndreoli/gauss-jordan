#include<stdio.h>
#include<math.h>
#define N 3
#define M 4

int main(void) {
	
	float mat[N][M], num;
	int i, j;

	printf("Ingrese las componentes de la matriz ampliada:\n\n");
 	
	for(i=0; i<N; i++){ 
	for(j=0; j<M; j++)
	{	printf("[%d][%d]:", i+1, j+1);
	    scanf("%f", &mat[i][j]);
	}}

//PROCESO..
	// e fila 1 / [0][0]
        if( mat[0][0] != 0){
		num = mat[0][0];
	    for(j=0;j<M;j++){
	    mat[0][j] =  mat[0][j] / num;
	    }}
    // e fila 2 / [1][0]
        if( mat[1][0] != 0){
		num = mat[1][0];
	    for(j=0;j<M;j++){
		mat[1][j] =  mat[1][j] / num;
	    }}
    // e fila 3/ [2][0]
        if( mat[2][0] != 0){
	    num = mat[2][0];
	    for(j=0;j<M;j++){
		mat[2][j] =  mat[2][j] / num;
	    }}

	// e 21(-[1][0])  
	mat[1][0] = mat[1][0] + (-1 * mat[1][0]);
	mat[1][1] = mat[1][1] + (-1 * mat[1][0]);	
	mat[1][2] = mat[1][2] + (-1 * mat[1][0]);	
	mat[1][3] = mat[1][3] + (-1 * mat[1][0]);	
	
	// e 31(-[2][0])
    mat[2][0] = mat[2][0] + (-1 * mat[2][0]);
	mat[2][1] = mat[2][1] + (-1 * mat[2][0]);	
	mat[2][2] = mat[2][2] + (-1 * mat[2][0]);	
	mat[2][3] = mat[2][3] + (-1 * mat[2][0]);	

	// Si el componente [1][1] es distinto de 1, entonces divido toda esa fila por el valor de ese componente.
	if( mat[1][1] != 1){
		num = mat[1][1];
		for(j=0;j<M;j++){
			mat[1][j] =  mat[1][j] / num;
		}}

	// e 12(-[0][1])
	mat[0][0] = mat[0][0] + (mat[1][0] * ( -1 * mat[0][1]));
	mat[0][1] = mat[0][1] + (mat[1][1] * ( -1 * mat[0][1]));	
	mat[0][2] = mat[0][2] + (mat[1][2] * ( -1 * mat[0][1]));		
	mat[0][3] = mat[0][3] + (mat[1][3] * ( -1 * mat[0][1]));		
	
	// 32(-[2][1])
	mat[2][0] = mat[2][0] + (mat[1][0] * ( -1 * mat[2][1]));
	mat[2][1] = mat[2][1] + (mat[1][1] * ( -1 * mat[2][1]));	
	mat[2][2] = mat[2][2] + (mat[1][2] * ( -1 * mat[2][1]));
	mat[2][3] = mat[2][3] + (mat[1][3] * ( -1 * mat[2][1]));

	// Si el componente [2][2] es distinto de 1, entonces divido toda esa fila por el valor de ese componente.
	if( mat[2][2] != 1){
		num = mat[2][2];
		for(j=0;j<M;j++){
			mat[2][j] =  mat[2][j] / num;
		}}
	
    // e 23(-[1][2])
	mat[1][2] = mat[1][2] + (mat[2][2] * ( -1 * mat[1][2]));
	mat[1][3] = mat[1][3] + (mat[2][3] * ( -1 * mat[1][2]));			
	
	//e 13(-[0][2])
	mat[0][2] = mat[0][2] + (mat[2][2] * ( -1 * mat[0][2]));	
	mat[0][3] = mat[0][3] + (mat[2][3] * ( -1 * mat[0][2]));		

	
//IMPRIMIR MATRIZ Y RESULTADOS..
	printf("\nLa matriz es:\n");

for(i=0; i<N; i++)
{ 
	for(j=0; j<M; j++)
	{	printf("%.2f ", mat[i][j]);
	}
	printf("\n");
}

printf("\nResultado:\n");
printf(" x = %.2f\n y = %.2f\n z = %.2f", mat[0][3], mat[1][3], mat[2][3]);

	return 0;
}
