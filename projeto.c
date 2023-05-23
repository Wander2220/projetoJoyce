#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define maximoUsuarios 1000

int totalusuarios = 0, mainid[maximoUsuarios], mainbackupId[maximoUsuarios], mainvacina[maximoUsuarios], mainbackupVacina[maximoUsuarios];
double mainaltura[maximoUsuarios], mainbackupAltura[maximoUsuarios];
char mainnome[maximoUsuarios][50], mainbackupNome[maximoUsuarios][50], mainemail[maximoUsuarios][50], mainbackupEmail[maximoUsuarios][50], mainsexo[maximoUsuarios][20], mainbackupSexo[maximoUsuarios][20], mainendereco[maximoUsuarios][50], mainbackupEndereco[maximoUsuarios][50];

int incluirUsuarios(){
	char nome[50], email[50], endereco[50], sexo[10];
	double altura;
	int id[5], vacina, retorno;
	
	if(totalusuarios >= maximoUsuarios){
		printf("o limite de usuarios foi atingido!\n");
		return -1;
	}
	id[5] = rand()% 100000;
	  
	printf("digite seu nome completo\n");
	fflush(stdin);
	fgets(nome, 50, stdin);
	printf("digite seu email\n");
    scanf("%s", email);
	do{
        retorno = 1;
        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@'){
                retorno = 0;
                break;
            }
        }
        if(retorno == 1){
            printf("email invalido, tente novamente\n");
            scanf("%s", email);
        }
    }
    while(retorno == 1);
    
    printf("digite seu sexo\n");
    scanf("%s", sexo);
    while(!(strcmp(sexo, "masculino")==0 || strcmp(sexo, "feminino")==0 || strcmp(sexo, "indiferente")==0)){
    	printf("sexo invalido!, digite novamente\n");
    	scanf("%s", sexo);
	}
	printf("digite seu endereco\n");
	fflush(stdin);
	fgets(endereco, 50, stdin);
	
	printf("digite sua altura\n");
	scanf("%lf", &altura);
	while(altura < 1.00 || altura > 2.00){
		printf("altura invalida, tente novamente\n");
		scanf("%lf", &altura);
	}
	
	printf("o usuario e vacinado? (1 para sim, 0 para nao)\n");
	scanf("%d", &vacina);
	while(!(vacina == 1 || vacina ==0)){
		printf("valor invalido, tente novamente, (1 para sim, 0 para nao)\n");
		scanf("%d", &vacina);
	}
	
	mainid[totalusuarios] = id[5];
	mainvacina[totalusuarios] = vacina;
	mainaltura[totalusuarios] = altura;
	strcpy(mainnome[totalusuarios], nome);
	strcpy(mainemail[totalusuarios], email);
	strcpy(mainendereco[totalusuarios], endereco);
	strcpy(mainsexo[totalusuarios], sexo);
	
	totalusuarios++;
	
	return 0;
}
int editarUsuario(){
	
	char nome[50], email[50], endereco[50], sexo[10];
	double altura;
	int id[5], vacina, retorno;
	
	printf("edite um usuario\n");
	printf("digite o email do usuario\n");
	scanf("%s", email);
	for (int i = 0; i < totalusuarios; i++){
		if(strcmp(mainemail[i], email)==0){
		
		printf("digite seu nome completo\n");
		fflush(stdin);
		fgets(nome, 50, stdin);
		
		printf("digite seu email\n");
	    scanf("%s", email);
		do{
	        retorno = 1;
	        for (int i = 0; i < strlen(email); i++)
	        {
	            if (email[i] == '@'){
	                retorno = 0;
	                break;
	            }
	        }
	        if(retorno == 1){
	            printf("email invalido, tente novamente\n");
	            scanf("%s", email);
	        }
	    }
	    while(retorno == 1);
	    
	    printf("digite seu sexo\n");
	    scanf("%s", sexo);
	    while(!(strcmp(sexo, "masculino")==0 || strcmp(sexo, "feminino")==0 || strcmp(sexo, "indiferente")==0)){
	    	printf("sexo invalido!, digite novamente\n");
	    	scanf("%s", sexo);
		}
		printf("digite seu endereco\n");
		fflush(stdin);
		fgets(endereco, 50, stdin);
		
		printf("digite sua altura\n");
		scanf("%lf", &altura);
		while(altura < 1.00 || altura > 2.00){
			printf("altura invalida, tente novamente\n");
			scanf("%lf", &altura);
		}
		
		printf("o usuario e vacinado? (1 para sim, 0 para nao)\n");
		scanf("%d", &vacina);
		while(!(vacina == 1 || vacina ==0)){
			printf("valor invalido, tente novamente, (1 para sim, 0 para nao)\n");
			scanf("%d", &vacina);
		}
		mainvacina[i] = vacina;
		mainaltura[i] = altura;
		strcpy(mainnome[i], nome);
		strcpy(mainemail[i], email);
		strcpy(mainendereco[i], endereco);
		strcpy(mainsexo[i], sexo);
		}
	}
}

int buscarUsuario(){
	
	char email[50];
	
	printf("digite o email do usuario\n");
	scanf("%s", email);
	for(int i = 0; i < totalusuarios; i++){
	if(strcmp(mainemail[i], email)==0){
		printf("usuario encontrado\n");
		printf("id: %d\n", mainid[i]);
		printf("nome: %s\n", mainnome[i]);
		printf("email: %s\n", mainemail[i]);
		printf("endereco: %s\n", mainendereco[i]);
		printf("sexo: %s\n", mainsexo[i]);
		printf("altura: %.2lf\n", mainaltura[i]);
		printf("vacinado: %d\n", mainvacina[i]);
}
	else{
		printf("email nao encontrado\n");
	}
}
}
int todosUsuarios(){
	for(int i = 0; i < totalusuarios; i++){
		printf("usuario: \n");
		printf("id: %d\n", mainid[i]);
		printf("nome: %s\n", mainnome[i]);
		printf("email: %s\n", mainemail[i]);
		printf("endereco: %s\n", mainendereco[i]);
		printf("sexo: %s\n", mainsexo[i]);
		printf("altura: %.2lf\n", mainaltura[i]);
		printf("vacinado: %d\n", mainvacina[i]);
	}
}
int backupUsuarios(){
	
	int prosseguir;
	
	printf("deseja prosseguir?(1 para sim, 0 para nao)\n");
	scanf("%d", &prosseguir);
			if(prosseguir == 1){
				for(int i = 0; i < totalusuarios; i++){
				printf("fazendo backup.....\n");
				strcpy(mainbackupNome[i], mainnome[i]);
				strcpy(mainbackupEmail[i], mainemail[i]);
				strcpy(mainbackupEndereco[i], mainendereco[i]);
				strcpy(mainbackupSexo[i], mainsexo[i]);
				mainbackupAltura[i] = mainaltura[i];
				mainbackupVacina[i] = mainvacina[i];
				printf("backup realizado com sucesso!!!\n");
			}
		}
			else if(prosseguir == 0){
				printf("retornando\n");
			}
			else{
				printf("opcao invalida\n");
			}
}
int restaurarUsuario(){
	
	int prosseguir;
	
	printf("deseja prosseguir?(1 para sim, 0 para nao)\n");
	scanf("%d", &prosseguir);
	
		if(prosseguir == 1){
			for(int i = 0; i < totalusuarios; i++){
				printf("fazendo restauracao.....\n");
				strcpy(mainnome[i], mainbackupNome[i]);
				strcpy(mainemail[i], mainbackupEmail[i]);
				strcpy(mainendereco[i], mainbackupEndereco[i]);
				strcpy(mainsexo[i], mainbackupSexo[i]);
				mainaltura[i] = mainbackupAltura[i];
				mainvacina[i] = mainbackupVacina[i];
				printf("restauracao realizada com sucesso!!!\n");
				}
			}
			else if(prosseguir == 0){
				printf("retornando\n");
			}
			else{
				printf("opcao invalida\n");
			}
}
int main(){
	
	char opcao=' ';
	
	while(opcao != '0'){
		printf("digite a opcao desejada!\n");
		printf("1 - incluir ate 1000 usuarios\n2 - edite um usuario\n3 - exclua um usuario\n4 - busque um usuario pelo email\n5 - imprima todos usuarios cadastrados\n6 - faca backup dos usuarios cadastrados\n7 - faca restauracao dos dados\n0 - fechar plataforma\n");
		fflush(stdin);
		scanf("%c", &opcao);
		
		switch (opcao){
			case '1':
			incluirUsuarios();
			break;
			case '2':
			editarUsuario();
			break;
			case '3':
			
			break;
			case '4':
			buscarUsuario();
			break;
			case '5':
			todosUsuarios();
			break;
			case '6':
			backupUsuarios();
			break;
			case '7':
			restaurarUsuario();
			break;
			case '0':
			printf("obrigado pela preferencia!...\n");
			break;
			default:
			printf("opcao invalida!");
			break;
		}
	}
	return 0;
}