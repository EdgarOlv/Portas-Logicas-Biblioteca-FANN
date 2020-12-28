#include <stdio.h>
#include "floatfann.h"

int main()
{
    fann_type *calc_out;
    fann_type input[3];

    struct fann *ann = fann_create_from_file("nand_float.net");

    input[0] = -1;
    input[1] = 1;
    input[2] = 1;
    calc_out = fann_run(ann, input);

    printf("nand test (%f,%f,%f) -> %f\n", input[0], input[1], input[2], calc_out[0]);

    fann_destroy(ann);
    return 0;
}
