# BounceGIFCreator

This little pet project allows to compute GIFS as shown below. Wrote this for fun one 
lonely evening.

## Example 

![Alt text](readme_gif.gif)


## Getting Started

You'll need C++ Compiler version 20+ and libpng library.

Clone this repo:

```shell
git clone https://github.com/armalko/BounceGIFCreator
```

Install `libpng`. 

Linux:

```shell
sudo apt-get install libjpeg-dev libpng-dev
```

Mac-OS:

```shell
brew install libpng libjpeg
```

<b>Now you ready to build the project!</b>

Locate to folder using shell and run following:

```shell
cmake build -o built_file
```

And run 

```shell
./build_file
```

This will start the program.


## Recompiling PNG's to GIF

As you could noticed, code will produce N png-files, not one GIF. To merge 
them all together I propose using ffmpeg lib. Locate to build directory and run following:

```shell
ffmpeg -framerate 30 -i image_%d.png -loop 0 output.gif
```

If colors seem off, you can try to make custom palette:

```shell
ffmpeg -i image_%d.png -vf "palettegen" -y palette.png
```

And then use it to create better looking GIF:

```shell
ffmpeg -framerate 30 -i jopa_%d.png -i palette.png -lavfi "paletteuse" -y output.gif
```

## Next steps:

If I will find free time, I'll do the following steps:

- Move from using ffmpeg and produce GIF from C++ code.
- Add circles support
- Add UI for input of your own figures
- Add GUI...

If anyone is interested in development of this project feel free to contact me or just make PR's. 
