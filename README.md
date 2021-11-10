# DayPaper
## Solução básica de wallpaper dinâmico para Linux

### Introdução

A maioria das engines de wallpapers animados são focadas em gifs, vídeos e slides mais rápidos. E também rodam de forma assíncrona ao relógio do computador, esse projeto visa criar um wallpaper que siga o horário do dia e possa funcionar com sets de imagens variados.

### Get Started

A primeira coisa a se fazer é conseguir um vídeo ou set de imagens para usar, eu uso esse aqui: https://www.youtube.com/watch?v=FdPzO8Vlp2U.

Agora você deve acertar os pontos de início em fim. O dia tem 1440 minutos, e vamos precisar de 1440 frames. Como fazer isso: Abra um editor de vídeo, e em um projeto de 30 fps, ajuste a duração (sem cortar, mude a velocidade) para exatos 48 segundos. (pode ser necessário mudar o começo, mas se vc tem um ciclo arrumado, corte o vídeo onde ele deve começar e coloque a segunda metade no começo da timeline.
Mande renderizar para imagem, ou use: ffmpeg -i video.algumacoisa %d.png Esse será seu set de imagens.
Coloque o set em uma pasta e marque o endereço dessa pasta.
Crie uma imagem now.png e sete ela como wallpaper.
Coloque o set.sh e o sel em algum lugar no sistema de arquivos e de preferência na mesma pasta.
Copie o arquivo de exemplo do cron e mude os campos necessários, as instruções estão nos arquivos.

Se você acertou os caminhos e fez tudo certo, seu wallpaper será trocado a cada 1 minuto.
