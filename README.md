#### 🚧 Work in progress 🚧
# Shoot 'em up game

A [Shoot 'em up](https://en.wikipedia.org/wiki/Shoot_%27em_up) game I'm working on
### Dependencies

- [SDL2](http://libsdl.org)
- gcc
- make

#### Debian and derivatives

```bash
  sudo apt install libsdl2-2.0-0
  sudo apt install libsdl2-dev
  sudo apt install libsdl2-image-2.0-0
  sudo apt install libsdl2-image-dev
```

#### Fedora
```bash
  sudo dnf install SDL2
  sudo dnf install SDL2-devel
  sudo dnf install SDL2_image
  sudo dnf install SDL2_image-devel
```
### Compiling

```
make build
```
### Assets
Keep in mind this repository uses [Git LFS](https://git-lfs.com/), you need that to get the assets back, after cloning, run:
```bash
cd shoot_em_up
git lfs pull
```
