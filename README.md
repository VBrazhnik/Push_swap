# Push_swap

Push_swap is a School 42 project. The purpose of this project is to create sorting algorithm.

[`push_swap.en.pdf`](/push_swap.en.pdf) is the task file.

You can check [wiki-page](../../wiki/Algorithm) if you want to read description of created algorithm.

### Benchmarks

To test my `push_swap` I used [own bash script](benchmark.sh).

Result of solving 10 000 cases with **100 numbers**:

![benchmark_100](/images/benchmark_100.png)

Result of solving 10 000 cases with **500 numbers**:

![benchmark_500](/images/benchmark_500.png)

### Bonuses

Created `checker` has two additional modes:

* `-v` — verbose mode
* `-c` — color mode

<p align="center">
  <img src="/images/checker_(verbose_mode).png" width="48%" alt="checker (verbose mode)" align="left"/>
  <img src="/images/checker_(verbose_and_color_mode).png" width="48%" alt="checker (verbose and color mode)"/>
</p>

Also this project has a simple visualizer. **(macOS is only supported)**

![visualizer](/images/visualizer.png)

### How to clone?

This repository includes submodule. So if you want to clone it, you can use the following command:

```
git clone --recurse-submodules <repository url>
```

If you will use `git clone <repository url>` instead of, you will get the empty `libft` folder.
