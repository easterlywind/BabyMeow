# BabyMeow
<h1 align="center">
    <img width="4%" src="https://user-images.githubusercontent.com/71594219/118890082-460cb380-b928-11eb-8124-40dca15c13c0.png">
    BabyMeow 😻
</h1>
<p align="center">UET - <i>Assignment about game</i></p>
<p align="center"><a href="https://github.com/easterlywind/BabyMeow"><img width="40%" src="https://github.com/easterlywind/BabyMeow/blob/main/assets/image/logo.png"></a></p>
<br>


##  Mục lục
* [1. Cách cài đặt game](#cai-dat)
* [2. Mô tả về trò chơi](#mo-ta)
* [3. Các kĩ thuật lập trình](#ki-thuat)
* [4. Hỗ trợ](#ho-tro)

<a name="cai-dat"/>

## I, Hướng dẫn cài đặt và chạy game

#### Điều kiện:
- **A** configured C++ compiler, preferably [MinGW](https://sourceforge.net/projects/mingw/) or [MinGW-w64](https://www.mingw-w64.org/)

#### Clone the repository:
```bash
git clone https://github.com/easterlywind/BabyMeow
cd BabyMeow
```

#### Build the project:
```bash
mingw32-make
mingw32-make run
```


<a name="mo-ta"/>

## II, Mô tả về trò chơi
## Demo



https://github.com/easterlywind/BabyMeow/blob/main/assets/image/BabyMeow%202024-05-15%2009-12-30.mp4



**Thể loại:** `Game dodge`

Người chơi điều khiển con mèo di chuyển bằng cách nhấp chuột để sử dụng súng bán, con mèo sẽ di chuyển theo hướng ngược với hướng bấm chuột và ăn pate, kho báu để kiếm được số điểm cao nhất

Ăn 1 hộp pate sẽ được cộng 1 điểm và 2 viên đạn

Ăn 1 rương kho báu sẽ được cộng 5 điểm và 5 viên đạn

Con chó sẽ xuất hiện ngẫu nhiên, người chơi chạm phải con chó sẽ chết

Khi súng hết đạn thì người chơi k thể di chuyển được

<a name = "ki-thuat"/>

### III, Các kỹ thuật lập trình được sử dụng
  - Sử dụng thư viện đồ họa SDL
  - Lập trình hướng đối tượng(OOP)
  - Con trỏ, cấp phát động
  - Sử dụng các thuật toán cơ bản như thuật toán xử lý va chạm, sinh ngẫu nhiên, ...

<a name = "ho-tro"/>

### IV, Hỗ trợ
- #### Sử dụng canva để design
- #### Language: C++ 17
- [SDL2](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.3) 2.28.3, [SDL_image](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.6.3) 2.6.3, [SDL_ttf](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.20.2) 2.20.2, [SDL_mixer](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.6.3) 2.6.3


- #### Compiler: [MinGW GCC](https://github.com/niXman/mingw-builds-binaries/releases/tag/13.2.0-rt_v11-rev0) 64-bit

- #### Version control: [Git](https://git-scm.com/) 2.42.0.windows.2

