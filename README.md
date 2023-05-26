# quantizer
This is a full reversal of quantizer' structs, fonts and binaries and fully working (except of it may bugging).

`WaitOnInterrupt` function is a total meme function I wrote because I was lazy to implement wipet's poorely written interrupt handler to make a "wait on pit" function.

The original WaitOnInterrupt function is a memer too, all it does is hanging the whole system until a PIT interrupt occurs then EOI omg!

The interrupt handler is also a meme, hasn't been put any effort into it as there is just one handler for all faults and irqs???? And it also EOIs if a fault occurs, so no handling for faults at all, fuck the cpu bro, let it run.

#takedown

# How to compile and run

Open the .sln and compile the cpp project.
1. Hex edit the outputed executable found in the `Release` folder and copy its content.
2. Open `boot.bin` found in this repository with the hex editor and paste the executable binary at the bottom of the file.
3. Save, run boot.bin with qemu and profit.

Tutorial https://cdn.discordapp.com/attachments/1111375384248844461/1111776921915764836/NVIDIA_Share_9zPgGDEzsk.mp4
