#include <stdio.h>
#include <stdlib.h>

// Biblioteca para utilizar a função sleep()
#include <unistd.h>

// Biblioteca para configurar a localização para português
#include <locale.h>

// Definição do tamanho da barra
#define length 25

// Função para imprimir a mensagem de introdução
void introMessage() {
    // Mensagem de boas-vindas e explicação do programa
    printf("\n Olá! Eu sou um cofre virtual...");
    printf("\n Eu represento uma simulação digital de um mecanismo de segurança.");

    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Explicação sobre a senha/combinação e como abrir o cofre
    printf("\n\n Acho que para descobrir se eu te pertenço, será necessário acertar a senha/combinação, para que, assim, eu possa abrir\n e entregá-lo seus pertences :)");

    // Aguarda 2 segundos antes de continuar
    sleep(2);

    // Explicação sobre o funcionamento do cofre e a barra de deslizamento
    printf("\n\n Aqui está o funcionamento: possuo uma barra de 25 posições, começando na posição 10, que pode ser movida até 4 vezes.");
    printf("\n Durante cada movimento, os números entre os novos limites estabelecidos serão contados.");

    // Informação sobre a posição inicial e o início dos movimentos
    printf("\n\n O número 7, na posição 10, marca o início dos movimentos.\n A partir deste ponto, você moverá os limites para revelar a combinação correta.");

    // Mensagem de pronto para começar
    printf("\n\n Agora, com todas as instruções, podemos começar!\n\n");
}

// Função para analisar a combinação
void combinationAnalysis() {
    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Mensagem indicando que a combinação está sendo analisada
    printf("\n Analisando combinação...");

    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Pontos indicando que a análise está em andamento
    printf("\n\n .");

    // Aguarda 1 segundo antes de continuar
    sleep(1);
    printf("    .");

    // Aguarda 1 segundo antes de continuar
    sleep(1);
    printf("    .");

    // Aguarda 1 segundo antes de continuar
    sleep(1);
}

// Função para imprimir a mensagem de abertura bem-sucedida do cofre
void successfulOpening() {
    // Mensagem de sucesso ao abrir o cofre
    printf("\n Muito bem! Parece que você me conhece bem e conseguiu abrir o cofre com sucesso...");
    printf("\n A combinação que você descobriu/encontrou ao final dos deslizamentos é a chave correta para me desbloquear!");

    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Mensagem indicando que o cofre está aberto e pronto para uso
    printf("\n\n Agora que me encontro aberto, você pode acessar seus pertences com segurança :)");
    printf("\n Por favor, lembre-se de fechar o cofre corretamente após a utilização para garantir sua segurança.");
    printf("\n\n Obrigado por utilizar meu serviço!\n");
}

// Função para imprimir a mensagem de abertura malsucedida do cofre
void unsuccessfulOpening() {
    // Mensagem de falha ao abrir o cofre
    printf("\n Que pena! Suas tentativas de abertura do cofre se esgotaram :(");
    printf("\n Parece que você não conseguiu encontrar a combinação correta para me abrir...");

    // Informação sobre a impossibilidade de acessar os pertences
    printf("\n\n Infelizmente, não poderei lhe entregar seus pertences neste momento.");

    // Mensagem de agradecimento e encerramento
    printf("\n\n Agradeço suas tentativas e lamento por qualquer incoveniente causado. Tenha um ótimo dia.\n");
}

int main() {
    // Configura a localização para português
    setlocale(LC_ALL, "portuguese");

    // Array representando a barra do cofre com valores de 1 a 8
    int safe_bar[length] = {1, 5, 7, 8, 2, 2, 7, 8, 2, 5, 7, 8, 2, 1, 5, 2, 7, 8, 2, 1, 1, 2, 7, 8, 2};

    // Variáveis para controlar o número de tentativas e os resultados dos deslizamentos
    int trys = 0, k, i, movements, return_option, closure_option, initial_position, position_to;
    int C1, C2, C5, C7, C8;

    // Chama a função para imprimir a mensagem de introdução
    introMessage();

    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Limpa a tela do console
    system("pause");
    system("cls");

    // Loop principal do programa
    do {
        // Inicializa as contagens dos números presentes na combinação
        C1 = 0;
        C2 = 0;
        C5 = 0;
        C7 = 1;
        C8 = 0;

        // Posição inicial da barra de deslizamento
        initial_position = 10;

        // Pede ao usuário o número de movimentos desejados para abrir o cofre
        printf("\n Primeiramente, preciso saber quantos deslizamentos/movimentos você deseja realizar.");
        printf("\n Para isso, me informe, a seguir, a quantidade de deslizamentos desejada por você para o processo de abertura.");
        printf("\n\n Observação: você deve realizar pelo menos 1 deslizamento e, no máximo, 4 deslizamentos totais.\n");

        // Loop para validar a entrada do usuário
        do {
            printf("\n º Informe a quantidade de deslizamentos a serem realizados: ");
            scanf("%d", &movements);

            if(movements <= 0) {
                printf("\n Não é possível abrir o cofre sem realizar nenhum movimento!\n");
            } else if(movements > 4) {
                printf("\n Não é possível realizar mais que 4 movimentos! Insira um número válido...\n");
            }
        } while((movements <= 0) || (movements > 4));

        // Mensagem indicando que o processo de abertura do cofre está prestes a começar
        printf("\n Ótimo! Agora com o número de movimentos a serem realizadas definido, podemos continuar para a abertura do cofre.\n\n");

        // Aguarda 2 segundos antes de continuar
        sleep(2);

        // Limpa a tela do console
        system("pause");
        system("cls");

        // Mensagem indicando que o usuário precisa informar as posições dos deslizamentos
        printf("\n Tudo pronto! Agora, com a informação do número de deslizamentos para o processo de abertura, podemos prosseguir.");
        printf("\n Nessa etapa, será necessário informar as posições desejadas para o deslocamento do limite.\n");

        // Variável de controle para sair do loop de deslizamentos
        int flag = 1;

        // Loop para solicitar as posições dos deslizamentos
        for(k = 0; (k < movements && flag); k++) {
            printf("\n º Informe o limite (posição) para o \"%dº\" deslocamento: ", k+1);
            scanf("%d", &position_to);

            // Verifica se a posição informada é válida
            if((position_to < 0) || (position_to > 24)) {
                // Mensagem de erro e opções para retornar ou encerrar o processo
                printf("\n Um número negativo ou superior ao comprimento da barra foi informado e, consequentemente, o deslocamento foi encerrado!\n");

                // Aguarda 3 segundos antes de continuar
                sleep(3);

                // Limpa a tela do console
                system("cls");

                // Mensagem para escolher entre retornar ou encerrar o processo
                printf("\n Ainda é possível retornar ao painel inicial de abertura do cofre...");
                printf("\n\n Para isso, abaixo há 2 opções disponíveis, dentre as quais você deve selecionar entre a 1º ou a 2º opção.");
                printf("\n º Digite \"1\" caso você queira retornar ao painel de deslizamentos.");
                printf("\n º Digite \"2\" caso você queira encerrar o processo de abertura do cofre.");

                // Solicitação da opção escolhida pelo usuário
                printf("\n\n Opção: ");
                scanf("%d", &return_option);

                // Switch para tratar a opção escolhida pelo usuário
                switch(return_option) {
                    // Caso o usuário queira retornar ao painel de deslizamentos
                    case 1:
                        printf("\n Como a 1º opção foi escolhida, você será, a seguir, redirecionado ao painel de deslizamentos.");

                        // Contagem regressiva para simular o redirecionamento
                        sleep(1);
                        printf("\n\n 3,");
                        sleep(1);
                        printf("    2,");
                        sleep(1);
                        printf("    1");
                        sleep(1);

                        // Limpa a tela do console
                        system("cls");

                        // Sinaliza que o loop de deslizamentos deve ser interrompido
                        flag = 0;

                        break;

                    // Caso o usuário queira encerrar o processo de abertura do cofre
                    case 2:
                        printf("\n Como a 2º opção foi escolhida, o processo de abertura do cofre será encerrado!");

                        // Contagem regressiva para simular o encerramento
                        sleep(1);
                        printf("\n\n 3,");
                        sleep(1);
                        printf("    2,");
                        sleep(1);
                        printf("    1\n");
                        sleep(1);

                        // Encerra o programa
                        exit(0);

                    // Caso o usuário tenha escolhido uma opção inválida
                    default:
                        printf("\n Nenhuma opção válida encontrada! Selecione entre as opções listadas acima.");
                }
                break;
            }

            // Verifica se o limite é maior que a posição inicial para contar os números no intervalo
            if (position_to > initial_position) {
                // Loop para contar os números no intervalo
                for (i = initial_position + 1; i <= position_to; i++) {
                    if (safe_bar[i] == 1) {
                        C1++;
                    } else if (safe_bar[i] == 2) {
                        C2++;
                    } else if (safe_bar[i] == 5) {
                        C5++;
                    } else if (safe_bar[i] == 7) {
                        C7++;
                    } else if (safe_bar[i] == 8) {
                        C8++;
                    }
                }
                initial_position = position_to;
            } else {
                // Loop para contar os números no intervalo
                for (i = initial_position - 1; i >= position_to; i--) {
                    if (safe_bar[i] == 1) {
                        C1++;
                    } else if (safe_bar[i] == 2) {
                        C2++;
                    } else if (safe_bar[i] == 5) {
                        C5++;
                    } else if (safe_bar[i] == 7) {
                        C7++;
                    } else if (safe_bar[i] == 8) {
                        C8++;
                    }
                }
                initial_position = position_to;
            }
        }

        // Verifica se o loop de deslizamentos não foi interrompido
        if(flag) {
            // Mensagem indicando que os movimentos foram concluídos e a combinação está sendo analisada
            printf("\n Perfeito! Agora, ao término dos movimentos estipulados anteriormente, já temos a combinação formada.");

            // Aguarda 3 segundos antes de continuar
            sleep(3);

            // Limpa a tela do console
            system("cls");

            // Verifica se a combinação está correta
            if((C1 == 5) && (C2 == 11) && (C5 == 3) && (C7 == 7) && (C8 == 6)) {
                // Chama a função para simular a análise da combinação
                combinationAnalysis();

                // Limpa a tela do console
                system("cls");

                // Mensagem de abertura bem-sucedida do cofre
                successfulOpening();

                // Aguarda 1 segundo antes de continuar
                sleep(1);

                // Limpa a tela do console
                system("pause");
                system("cls");

                // Mensagem de separação antes de retornar ao painel inicial
                printf("\n --------------------------------------/--------------------------------------\n\n");
                sleep(1);

                // Limpa a tela do console
                system("cls");

                // Mensagem indicando as opções disponíveis após a abertura do cofre
                printf("\n --------------------------------------/--------------------------------------\n");

                // Mensagem para escolher entre fechar o cofre ou encerrar o processo
                printf("\n Agora, com o cofre aberto, é possível fechá-lo novamente ou encerrar o processo de abertura.");
                printf("\n Abaixo há 2 opções disponíveis, dentre as quais você deve selecionar entre a 1º ou a 2º opção.");
                printf("\n º Digite \"1\" caso você queira fechar o cofre e retornar ao painel inicial.");
                printf("\n º Digite \"2\" caso você queira fechar o cofre e encerrar o processo de abertura definitivamente.");

                // Solicitação da opção escolhida pelo usuário
                printf("\n\n Opção: ");
                scanf("%d", &closure_option);

                // Mensagem de separação antes de executar a opção escolhida
                printf("\n --------------------------------------/--------------------------------------\n");

                // Switch para tratar a opção escolhida pelo usuário
                switch(closure_option) {
                    // Caso o usuário queira fechar o cofre e retornar ao painel inicial
                    case 1:
                        // Mensagem indicando que o cofre está sendo fechado e retornando ao painel inicial
                        printf("\n Fechando o cofre e redirecionando-lhe ao painel inicial de abertura do cofre...");

                        // Contagem regressiva para simular o fechamento e o redirecionamento
                        sleep(1);
                        printf("\n\n 3,");
                        sleep(1);
                        printf("    2,");
                        sleep(1);
                        printf("    1");

                        // Aguarda 1 segundo antes de continuar
                        sleep(1);

                        // Limpa a tela do console
                        system("cls");

                        // Reseta o contador de tentativas
                        trys = 0;

                        // Chama a função para imprimir a mensagem de introdução novamente
                        introMessage();

                        // Aguarda 1 segundo antes de continuar
                        sleep(1);

                        // Limpa a tela do console
                        system("pause");
                        system("cls");

                        break;

                    // Caso o usuário queira fechar o cofre e encerrar o processo de abertura definitivamente
                    case 2:
                        // Mensagem indicando que o processo de abertura do cofre está sendo encerrado
                        printf("\n Encerrando o processo de abertura do cofre de maneira definitiva...");

                        // Contagem regressiva para simular o encerramento
                        sleep(1);
                        printf("\n\n 3,");
                        sleep(1);
                        printf("    2,");
                        sleep(1);
                        printf("    1\n");

                        // Aguarda 1 segundo antes de continuar
                        sleep(1);

                        // Encerra o programa
                        exit(0);

                    // Caso o usuário tenha escolhido uma opção inválida
                    default:
                        printf("\n Nenhuma opção válida encontrada! Selecione entre as opções listadas acima.");
                }
            } else {
                // Incrementa o contador de tentativas
                trys++;

                // Chama a função para simular a análise da combinação
                combinationAnalysis();

                // Mensagem indicando que a combinação está incorreta e informando o número de tentativas restantes
                printf("\n\n Sua combinação final foi: | %d | %d | %d | %d | %d |\n\n", C1, C2, C5, C7, C8);

                // Aguarda 1 segundo antes de continuar
                sleep(1);

                // Mensagem indicando que a senha inserida está incorreta e informando o número de tentativas restantes
                printf("\n\n Hmmm... me parece que a senha inserida ao término dos deslizamentos está incorreta!");
                printf("\n Ainda lhe restam %d tentativa(s) até o fechamento completo do cofre.\n\n", 3-trys);

                // Aguarda 1 segundo antes de continuar
                sleep(1);

                // Limpa a tela do console
                system("pause");
                system("cls");
            }
        }
    } while(trys < 3);

    // Chama a função para imprimir a mensagem de abertura malsucedida do cofre
    unsuccessfulOpening();

    // Aguarda 1 segundo antes de continuar
    sleep(1);

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
