#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int Opcao;
int NumAcao = 0;
bool Sair = false;

struct Data{
    int ano;
    int mes;
    int dia;
};

struct AcaoPSE{
    int codigo;
    char escola[100];
    char tema[50];
    struct Data dataPrevista;
    char publicoAlvo[100];
    char responsavel[50];
    int qtdPrevistaParticipantes;
    char situacao[50];
    int qtdEfetivaParticipantes;
};

struct AcaoPSE Acoes[100];

void LimparEntrada();

void LimparTela();

void SairSistema();

void PausarSistema();

bool AcaoExiste(int codigo);

int LerInteiro();

void ExibirAcao(int indice);

void Menu();

void CadastrarAcao();

void ListarAcoes();

void ConsultarAcao();

void AtualizarAcao();

void GerarResumoGeral();


void LimparEntrada(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF){
	}
}


void LimparTela(){
	#if defined(_WIN32) || defined(_WIN64) 
		system("CLS");
	#else
		system("clear");
	#endif	
}


void PausarSistema(){
    printf("\nPressione Enter para continuar...");
	getchar();
}


bool AcaoExiste(int codigo){
    for(int i = 0; i < NumAcao; i++){
        if(Acoes[i].codigo == codigo){
            return true;
        }
    }

    return false;
}

int LerInteiro(){
    int valor;

    while(scanf("%i", &valor) != 1){
        printf("Entrada inválida! Digite apenas números.\n");
        LimparEntrada();
    }

    LimparEntrada();

    return valor;
}


void ExibirAcao(int Indice){
    printf("----------- Dados da Ação -----------\n");
    printf("Código da Ação: %i\n", Acoes[Indice].codigo);
    printf("Nome da escola: %s\n", Acoes[Indice].escola);
    printf("Tema da Ação: %s\n", Acoes[Indice].tema);
    printf("Data prevista: %d/%d/%d\n",
           Acoes[Indice].dataPrevista.dia,
           Acoes[Indice].dataPrevista.mes,
           Acoes[Indice].dataPrevista.ano);
    printf("Público Alvo: %s\n", Acoes[Indice].publicoAlvo);
    printf("Responsável: %s\n", Acoes[Indice].responsavel);
    printf("Qtd. prevista de Participantes: %i\n",
           Acoes[Indice].qtdPrevistaParticipantes);

    if(Acoes[Indice].qtdEfetivaParticipantes != -1){
        printf("Qtd. efetiva de Participantes: %i\n",
               Acoes[Indice].qtdEfetivaParticipantes);
    }

    printf("Situação da Ação: %s\n", Acoes[Indice].situacao);
    printf("--------- ------------- ---------\n\n");
}

void Menu(){
    LimparTela();

    printf("=========== Programa Saude na Escola ===========\n\n");
    printf("           01 - Cadastrar Ação\n");
    printf("           02 - Consultar Ação\n");
    printf("           03 - Listar Ações\n");
    printf("           04 - Atualizar Ação\n");
    printf("           05 - Gerar Resumo Geral\n");
    printf("           06 - Sair\n\n");
    printf("           Escolha uma opçao..\n");
    Opcao = LerInteiro();
}


void CadastrarAcao(){
    LimparTela();

    if(NumAcao >= 100){
        printf("Limite de cadastros máximos atingidos...");        
    }
    else{
        do{
            printf("Digite o código da Ação: ");
            Acoes[NumAcao].codigo = LerInteiro();

            if(AcaoExiste(Acoes[NumAcao].codigo)){
                printf("Esse código já está cadastrado!\n");            
            }
        }while(AcaoExiste(Acoes[NumAcao].codigo));

        
        do{
            printf("\nDigite o nome da Escola: ");
            fgets(Acoes[NumAcao].escola, 100, stdin);

            Acoes[NumAcao].escola[strcspn(Acoes[NumAcao].escola, "\n")] = '\0';

            if(strlen(Acoes[NumAcao].escola) == 0){
                printf("O nome da escola não pode ficar vazio!\n");
            }
        }while(strlen(Acoes[NumAcao].escola) == 0);

        
        do{
            printf("\nDigite o tema da Acao: ");
            fgets(Acoes[NumAcao].tema, 50, stdin);

            Acoes[NumAcao].tema[strcspn(Acoes[NumAcao].tema, "\n")] = '\0';

            if(strlen(Acoes[NumAcao].tema) == 0){
                printf("O tema não pode ficar vazio!\n");
            }
        }while(strlen(Acoes[NumAcao].tema) == 0);
        

        printf("\nInforme a data prevista para a Acao (dd/mm/yyyy): ");
        scanf("%d/%d/%d", 
              &Acoes[NumAcao].dataPrevista.dia,
              &Acoes[NumAcao].dataPrevista.mes,
              &Acoes[NumAcao].dataPrevista.ano);

        LimparEntrada();


        do{
            printf("\nInforme o público alvo: ");	
		    fgets(Acoes[NumAcao].publicoAlvo, 100, stdin);

            Acoes[NumAcao].publicoAlvo[strcspn(Acoes[NumAcao].publicoAlvo, "\n")] = '\0';

            if(strlen(Acoes[NumAcao].publicoAlvo) == 0){
                printf("O publico alvo não pode ficar vazio!\n");
            }
        }while(strlen(Acoes[NumAcao].publicoAlvo) == 0);


        do{
            printf("\nDigite o Nome do responsável: ");	
		    fgets(Acoes[NumAcao].responsavel, 50, stdin);

            Acoes[NumAcao].responsavel[strcspn(Acoes[NumAcao].responsavel, "\n")] = '\0';

            if(strlen(Acoes[NumAcao].responsavel) == 0){
                printf("O Nome do responsável não pode ficar vazio!\n");
            }
        }while(strlen(Acoes[NumAcao].responsavel) == 0);


        do{
            printf("\nDigite a quantidade prevista de participantes: ");
            Acoes[NumAcao].qtdPrevistaParticipantes = LerInteiro();

            if(Acoes[NumAcao].qtdPrevistaParticipantes < 0){
                printf("A quantidade não pode ser negativa!\n");
            }
        }while(Acoes[NumAcao].qtdPrevistaParticipantes < 0);

        strcpy(Acoes[NumAcao].situacao, "Planejada");

        Acoes[NumAcao].qtdEfetivaParticipantes = -1; //valor padrão do campo

        LimparTela();
        printf("\nCadastro efetuado com sucesso!");

        NumAcao++;
    }

    PausarSistema();
}

void ListarAcoes(){
    bool EncontrouAlguma = false;

    LimparTela();

    printf("=========== Ações PSE ===========\n\n");

    for (int i = 0; i < NumAcao; i++){    
        EncontrouAlguma = true;

        printf("Código da Ação: %i\n", Acoes[i].codigo);
        printf("Nome da escola: %s\n", Acoes[i].escola);
        printf("Tema da Ação: %s\n", Acoes[i].tema);
        printf("Data prevista: %d/%d/%d\n", Acoes[i].dataPrevista.dia, Acoes[i].dataPrevista.mes, Acoes[i].dataPrevista.ano );
        printf("Público Alvo: %s\n", Acoes[i].publicoAlvo);
        printf("Responsável: %s\n", Acoes[i].responsavel);
        printf("Qtd. prevista de Participantes: %i\n", Acoes[i].qtdPrevistaParticipantes);
        if(Acoes[i].qtdEfetivaParticipantes != -1){
            printf("Qtd. efetiva de Participantes: %i\n", Acoes[i].qtdEfetivaParticipantes);
        }
        printf("Situação da Ação: %s\n\n", Acoes[i].situacao);
        printf("---------------------------------\n\n");
    }

    if(!EncontrouAlguma){
        printf("Nenhuma Ação encontrada...\n");
    }

    PausarSistema();
}


void ConsultarAcao(){
    LimparTela();

    int Opcao;
    int Codigo;
    char Escola[100];
    char Tema[50];
    bool Encontrou = false;

    printf("=========== Consultar Ação ===========\n\n");

    printf("Escolha a opção para consulta: \n\n");
    printf("[1] - Código\n");
    printf("[2] - Escola\n");
    printf("[3] - Tema\n");
    Opcao = LerInteiro();

    LimparTela();
    printf("=========== Consultar Ação ===========\n\n");

    switch (Opcao){
        case 1:
            printf("Opção selecionada: [1] - Código\n");
            printf("Digite o código da Açao para consulta: ");
            Codigo = LerInteiro();

            printf("\n");

            for (int i = 0; i < NumAcao; i++){
                if(Acoes[i].codigo == Codigo){                
                    ExibirAcao(i);
                    Encontrou = true;
                    break;
                }
            }    
            break;
        case 2:
            printf("Opção selecionada: [2] - Escola\n");
            printf("Digite o nome da Escola para consulta: ");
            fgets(Escola, 100, stdin);
            Escola[strcspn(Escola, "\n")] = '\0';

            LimparTela();
            printf("=========== Consultar Ação ===========\n\n");
            printf("Opção selecionada: [2] - Escola\n");
            printf("Escola: %s\n\n", Escola);

            for (int i = 0; i < NumAcao; i++){
                if(strcmp(Acoes[i].escola, Escola) == 0){
                    ExibirAcao(i);                    
                    Encontrou = true;
                }
            }    
            break;
        case 3:
            printf("Opção selecionada: [3] - Tema\n");
            printf("Digite o tema para consulta: ");
            fgets(Tema, 50, stdin);
            Tema[strcspn(Tema, "\n")] = '\0';

            LimparTela();
            printf("=========== Consultar Ação ===========\n\n");
            printf("Opção selecionada: [3] - Tema\n");
            printf("Tema: %s\n\n", Tema);

            for (int i = 0; i < NumAcao; i++){
                if(strcmp(Acoes[i].tema, Tema) == 0){
                    ExibirAcao(i);                    
                    Encontrou = true;
                }
            } 
            break;
        default:
            printf("Opção inválida...");
            PausarSistema();
            return;
    }

    if(!Encontrou){
        printf("\nAção não encontrada...");
    }

    PausarSistema();
}

void AtualizarAcao(){
    int CodAcao;
    int OpcaoAtualizar;
    int IndiceAcao = -1;

    LimparTela();

    printf("=========== Atualizar Situação PSE ===========\n\n");

    if(NumAcao == 0){
        printf("Nenhuma Ação cadastrada!\n");
        PausarSistema();
        return;
    }

    printf("Qual Ação deseja atualizar?\n");
    CodAcao = LerInteiro();

    for(int i = 0; i < NumAcao; i++){
        if(Acoes[i].codigo == CodAcao){
            IndiceAcao = i;
            break;
        }    
    }

    if(IndiceAcao == -1){
        printf("\nAção não encontrada...\n");
        PausarSistema();

        return;
    }

    LimparTela();

    printf("=========== Atualizar Situação PSE ===========\n\n");

    printf("Situação da Ação selecionada: %s\n\n", Acoes[IndiceAcao].situacao);
    printf("[1] - Planejada\n");
    printf("[2] - Realizada\n");
    printf("[3] - Cancelada\n\n");
    printf("Seleciona uma das opções: ");
    OpcaoAtualizar = LerInteiro();

    switch(OpcaoAtualizar){
        case 1:
            strcpy(Acoes[IndiceAcao].situacao, "Planejada"); 
            Acoes[IndiceAcao].qtdEfetivaParticipantes = -1;
            break;
        case 2:
            strcpy(Acoes[IndiceAcao].situacao, "Realizada");
            break;
        case 3:
            strcpy(Acoes[IndiceAcao].situacao, "Cancelada");
            Acoes[IndiceAcao].qtdEfetivaParticipantes = -1;
            break;   
        default:
            printf("\nOpção inválida...\n");
            PausarSistema();
            return;
    }

    if(OpcaoAtualizar != 2){
       printf("\nAtualização realizada com sucesso!\n");
       PausarSistema();
       
       return;
    }

    LimparTela();

    printf("=========== Atualizar Situação PSE ===========\n\n");    
    printf("Situação selecionada: %s\n\n", Acoes[IndiceAcao].situacao);

    do{
        printf("\nInforme a quantidade efetiva de Participantes: ");
        Acoes[IndiceAcao].qtdEfetivaParticipantes = LerInteiro();

        if(Acoes[IndiceAcao].qtdEfetivaParticipantes < 0){
            printf("\nA quantidade não pode ser negativa!");
        }

    }while(Acoes[IndiceAcao].qtdEfetivaParticipantes < 0);

    printf("\nAtualização realizada com sucesso!\n");
    PausarSistema();
}

void GerarResumoGeral(){
    int QtdPlanejadas    = 0;
    int QtdRealizadas    = 0;
    int QtdCanceladas    = 0;
    int TotalParticipantes = 0;
    int TotalPrevistos   = 0;
    double PercParticipacao = 0;

    LimparTela();

    printf("=========== Resumo Geral ===========\n\n");

    if(NumAcao == 0){
        printf("Nenhuma Ação cadastrada!\n");
        PausarSistema();
        return;
    }

    LimparTela();

    for(int i = 0; i < NumAcao; i++){
        if(strcmp(Acoes[i].situacao, "Planejada") == 0){
            QtdPlanejadas++;
        }
        else if(strcmp(Acoes[i].situacao, "Realizada") == 0){
            QtdRealizadas++;
        }
        else if(strcmp(Acoes[i].situacao, "Cancelada") == 0){
            QtdCanceladas++;
        }

        if(Acoes[i].qtdEfetivaParticipantes != -1){
            TotalParticipantes += Acoes[i].qtdEfetivaParticipantes;
        } 
        TotalPrevistos += Acoes[i].qtdPrevistaParticipantes;
    }

    if(TotalPrevistos > 0){
    PercParticipacao = (TotalParticipantes * 100.0) / TotalPrevistos;
    }
    else{
        PercParticipacao = 0;
    }

    printf("=========== Resumo Geral ===========\n\n");
    printf("Qtd. de Ações: %i\n", NumAcao);
    printf(" ->Planejadas: %i\n", QtdPlanejadas);
    printf(" ->Realizadas: %i\n", QtdRealizadas);
    printf(" ->Canceladas: %i\n", QtdCanceladas);
    printf("Total de Participantes: %i\n", TotalParticipantes);
    printf("Porcentagem de participação: %.2lf%%\n", PercParticipacao);
    printf("--------- ------------- ---------");

    PausarSistema();
}

void SairSistema(){
    LimparTela();
    Sair = true;

    printf("Saindo do sistema...");
}

int main(){    
    setlocale(LC_ALL, ".UTF8");

    do
    {
        Menu();
        switch(Opcao){
            case 1:
                CadastrarAcao();
                break;
            case 2:
                ConsultarAcao();
                break;
            case 3:
                ListarAcoes();
                break;
            case 4:
                AtualizarAcao();
                break;
            case 5:
                GerarResumoGeral();
                break;
            case 6:
                SairSistema();
                break;
            default:
                printf("Opção inválida...\n");
                PausarSistema();
        }
    } while (Sair == false);  
}
