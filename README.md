Esse projeto é uma atividade feita para o curso de sistemas embarcados do Embarcatech - Cepedi. Trata-se de um experimento utilizando funções de temporização.
A tarefa pede que seja desenvolvido um temporizador periódico que simula um semáforo de trânsito, alternando entre vermelho, amarelo e verde a cada 3 segundos enquanto, ao mesmo tempo, imprime a cada segundo uma mensagem que avisa qual a cor do sinal no momento e o que ela significa.

O código foi projetado para ser executado numa Rasberry Pi Pico W e foi simulado no Wokwi, cujo diagrama pode ser visto no arquivo _diagram.json_.

A atividade pede para que, se possível, o experimento seja testado na placa de desenvolvimento BitDogLab.
Para tal, antes de compilar o código, o usuário deve seguir a instrução da linha 41, que avisa para comentar a função ***bool repeating_timer_callback(struct repeating_timer *t)*** acima dela e descomentar a abaixo.
Isso é necessário pois a função abaixo utiliza o LED RGB da BitDogLab, onde a cor amarela é uma junção de vermelho e verde, enquanto na simulação é possível colocar diretamente um LED amarelo.
Por padrão, este projeto prioriza a função necessária para simulação, deixando sua outra versão comentada.

Para observar a execução do código na BitDogLab, pode-se acessar o link abaixo:
[https://drive.google.com/file/d/1BeKuUSFhFojVeoa5RNKuloaET0rUbCnE/view?usp=drivesdk]
