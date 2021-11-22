# DayPaper
## Solução básica de wallpaper dinâmico para Linux (Não testado em Windows)

### Introdução

A maioria das engines de wallpapers animados são focadas em gifs, vídeos e slides mais rápidos. E também rodam de forma assíncrona ao relógio do computador, esse projeto visa criar um wallpaper que siga o horário do dia e possa funcionar com sets de imagens variados.

### Get Started

A primeira coisa a se fazer é conseguir um vídeo ou set de imagens para usar, eu uso esse aqui: https://www.youtube.com/watch?v=FdPzO8Vlp2U.

Agora você deve acertar os pontos de início em fim. O dia tem 1440 minutos, e vamos precisar de 1440 frames. Como fazer isso: Abra um editor de vídeo, e em um projeto de 30 fps, ajuste a duração (sem cortar, mude a velocidade) para exatos 48 segundos. (pode ser necessário mudar o começo, mas se vc tem um ciclo arrumado, corte o vídeo onde ele deve começar e coloque a segunda metade no começo da timeline.

Mande renderizar para imagem, ou use: ffmpeg -i video.algumacoisa %d.png Esse será seu set de imagens.
Coloque o set em uma pasta e marque o endereço dessa pasta.

Crie uma imagem now.png na mesma pasta e sete ela como wallpaper.

Crie uma entrada de inicialização do appimage no sistema para que ele seja executado após o boot. Se você usa o AppImage Launche vai querer integrar ele antes.

No comando de inicialização passe os argumentos como: pasta_das imagens fuso_horário (Brasil é -3) intervalo_em_milisegundos.

Exemplo: /home/talkys/Daypaper/ -3 60000

Desse jeito a atualização sera executada a cada 1 minuto.

Se você acertou os caminhos e fez tudo certo, seu wallpaper será trocado a cada 1 minuto.
