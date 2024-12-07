# Malha Ferroviária
Trabalho da Segunda Unidade da Disciplina de Sistemas Operacionais (IMD0036). O trabalho consiste no desenvolvimento de uma malha ferroviária que comporta 5 trens, todos circulando no sentido horário. 

# Componentes:
Flawbert Costa e Mariana Timbó.

# 1. Estrutura do Código

    Classe Trem:
        Representa um trem com atributos como ID, posição (x, y), velocidade, mutexes compartilhados e o tamanho do passo.
        Possui métodos para manipulação de velocidade, inverter o movimento e executar o deslocamento com controle de regiões críticas.

    Método run():
        Controla o loop principal do movimento do trem.
        Emite sinais (emit updateGUI) para atualizar a interface gráfica com as posições do trem.
        Usa mutexes para bloquear e desbloquear regiões críticas do trilho.

# 2. Gerenciamento de Mutexes

    Travamento e Destravamento:
        Antes de entrar em regiões críticas (seções compartilhadas), o trem trava o mutex correspondente.
        Ao sair da região crítica, o mutex é destravado.
        Isso previne colisões quando dois trens tentam acessar a mesma seção ao mesmo tempo.

    Movimento Reverso:
        Se o trem está se movendo para trás (indicado pelo passo negativo), mutexes podem ser desbloqueados imediatamente para evitar bloqueios desnecessários.

# 3. Manipulação de Velocidade

    Método setVelocidade(int v):
        Ajusta a velocidade do trem com base no parâmetro v.
        Um valor de v <= 0 resulta na parada do trem.

# 4. Movimento nos Trilhos

    Cada trem possui regras específicas para se movimentar (baseadas no case do ID).
    As direções e restrições de movimento (em x ou y) são determinadas pela posição atual.
