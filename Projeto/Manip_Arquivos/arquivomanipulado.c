#include <stdio.h>

//==================Funçoes Para Manipulação do Arquivo=================//

int PrintText(int num, FILE *output, FILE *word, int *word_pos)
{ //printa o texto no arquivo de saida, ela checa se o arquivo n acabou e retorna true se acabar
	char string[100];

	while (num != 0) { //realizo esse processo o n° de vezes requisitados
		fseek(word, *word_pos, SEEK_SET);
		if (fscanf(word, "%s ", string) == EOF) { //se cheguei ao final do arquivo
			return 1;
		}

		fprintf(output, "%s ", string);

		num--;
		*word_pos = ftell(word); //defino a nova posição no arquivo
	}

	//verifica se ainda existe palavras para continuar os outros comandos
	if (fgetc(word) == EOF) {
		fprintf(output, "\n");
		return 1;             //cheguei ao final
	}
	fseek(word, -2, SEEK_CUR); //volta 2 pois a funçao avança 1 e quero estar antes do espaço

	fprintf(output, "\n");
	return 0; //não cheguei ao final do arquivo
}

void RewindWordPos(FILE *word, int *word_pos, int word_count, int num)
{ //essa funçao vai voltar a posiçao do arquivo o n° de palavras inserido no codigos.dat
	int n = word_count - num;
	char string[100];

	//se valor for maior que zero n voltei ao inicio
	if (n > 0) {
		fseek(word, 0, SEEK_SET); //retorna ao inicio

		while (n != 0) { //loop pra pegar a posiçao
			if (fscanf(word, "%s ", string) == -1) {
				break;
			}
			n--;
		}

		*word_pos = ftell(word); //voltei o n° de palavras requisitado

	} else {
		*word_pos = 0; //to no inicio, entao paro aqui
	}
}

void CheckEnd(FILE *cod, FILE *word, FILE *out)
{ //funçao que vai checar se sobraram palavras ou codigos
	int i = 0, n;
	char string[100];

	//se sobrou palavras
	while (fscanf(word, "%s ", string) != -1) {
		fprintf(out, "%s ", string);
		i++;

		if (i % 5 == 0)            //printa 5 palavras por linha
			fprintf(out, "\n");
	}

	//se sobrou codigos
	while (fscanf(cod, "%d ", &n) != -1) {
		fprintf(out, "%d ", n);
	}
}

//==================Principal=================//

int main(int argc, char const *argv[])
{
	//abre os arquivos
	FILE *cod = fopen("codigos.dat", "r");
	FILE *word = fopen("palavras.dat", "r");
	FILE *out = fopen("linhas.dat", "w");

	int i, num, num_pos = 0, word_pos = 0, word_count = 0, end = 0;

	//end -> verifica se cheguei ao final do arquivo

	if (cod == NULL ||
	    word == NULL) { //verifica se existe os arquivos, se não houver fecha o programa
		printf("Alguns arquivos estao faltando!");
		return 0;
	}

	//loop principal -> escaneia o codigo.dat e pega o valor para a operação
	while (fscanf(cod, "%d ", &num) != EOF && end != 1) {
		if (num == 0) {
			fprintf(out, "0\n");

		} else if (num > 0) {
			end = PrintText(num, out, word, &word_pos); //printa o valor e checa fim de arquivo
			word_count += num;

		} else {
			RewindWordPos(word, &word_pos, word_count, -num); //volta a posiçao
			end = PrintText(-num, out, word, &word_pos);
		}

		num_pos++;
	}

	if (!feof(cod)) { //volta o ultimo codigo escaneado, já que não foi utilizado -> -3 pois ele parou no posterior ao ultimo e tem espaço e sinal
		if(num_pos != 0)
			fseek(cod, -3, SEEK_CUR);
	}

	//funçao que checa se sobram codigos ou palavras
	CheckEnd(cod, word, out);

	//fecha os arquivos
	fclose(out);
	fclose(word);
	fclose(cod);

	return 0;
}
