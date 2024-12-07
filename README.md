# Malha Ferroviária
Trabalho da Segunda Unidade da Disciplina de Sistemas Operacionais (IMD0036). O trabalho consiste no desenvolvimento de uma malha ferroviária que comporta 5 trens, todos circulando no sentido horário. 

# Componentes:
Flawbert Costa e Mariana Timbó.

# Simulador de Trens com Qt e Mutexes

Este projeto implementa a simulação de cinco trens que se movem sobre trilhos compartilhados com áreas críticas protegidas por mutexes. A aplicação utiliza C++ e Qt Framework para a interface gráfica, gerenciando os movimentos dos trens e evitando colisões através de sincronização de threads.

Cada trem é uma entidade que se move em um trilho definido. Algumas áreas desses trilhos são compartilhadas entre dois ou mais trens, formando regiões críticas. Para evitar colisões, utilizamos mutexes (pthread_mutex_t) que garantem que apenas um trem acesse essas regiões de cada vez.

O comportamento dos trens é configurado individualmente com base em regras específicas para cada um (controladas por um identificador único, ID).
# 1. Características

    Movimento Sincronizado:
        Os trens são representados por threads que executam movimentos contínuos baseados em suas posições (coordenadas x e y).

    Controle de Áreas Críticas:
        Uso de mutexes para garantir exclusão mútua em seções compartilhadas do trilho.
        Liberação e aquisição de mutexes são gerenciadas dinamicamente durante o movimento dos trens.

    Movimento Reverso:
        Os trens podem inverter a direção de movimento utilizando o método inverter_passo().

    Ajuste de Velocidade:
        O usuário pode alterar a velocidade dos trens em tempo real através do método setVelocidade(int v).

    Atualização em Tempo Real:
        A posição dos trens é atualizada em uma interface gráfica por meio de sinais (emit updateGUI).

# 2. Requisitos do Sistema

    Linguagem: C++ (com suporte a C++11 ou superior).
    Framework: Qt (versão 5 ou superior).
    Bibliotecas: pthread (para manipulação de threads e mutexes).

# 3. Estrutura do Código
## 3.1 Arquivos Principais

    trem.h:
        Declara a classe Trem com seus atributos e métodos.
        Define a interface para manipulação da thread e sincronização.

    trem.cpp:
        Implementa os métodos da classe Trem.
        Controla o movimento de cada trem com base no ID.
        Gerencia mutexes para garantir segurança nas áreas críticas.

    Interface Gráfica (via Qt):
        Atualiza a posição dos trens em tempo real usando o método updateGUI.
        Permite interação com os trens, como ajuste de velocidade.

# 4. Funcionamento
## 4.1 Movimento dos Trens

Cada trem segue um trajeto definido com base no seu ID:

    Movimentos em eixos x e y são coordenados por condições específicas.
    Áreas críticas são protegidas com mutexes:
        Travamento: Antes de entrar em uma região compartilhada.
        Destravamento: Ao sair da região compartilhada.

# 5. Controle de Velocidade

A velocidade pode ser ajustada em tempo real. Um valor de velocidade igual a 0 faz o trem parar.
Inversão de Movimento

Os trens podem inverter seu sentido de movimento utilizando o método inverter_passo().
Execução

    Configuração do Ambiente:
        Certifique-se de que o Qt Creator e as bibliotecas pthread estão instalados no sistema.

    Compilação:
        Abra o projeto no Qt Creator.
        Compile o código utilizando um kit configurado com suporte a pthread.

    Execução:
        Execute o programa diretamente pelo Qt Creator.
        Observe os movimentos dos trens e ajuste suas velocidades ou direções pela interface.
