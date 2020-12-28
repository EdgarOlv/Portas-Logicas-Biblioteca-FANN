/*

4 3 1
-1 -1 1
-1
-1 1 1
1
1 -1 1
1
1 1 1
-1
*/

#include "fann.h"

#include "floatfann.h"

#include <stdio.h>

int main()

{

    const unsigned int num_input = 3;

    const unsigned int num_output = 1;

    const unsigned int num_layers = 3;

    const unsigned int num_neurons_hidden = 3;

    const float desired_error = (const float) 0.000;

    const unsigned int max_epochs = 100000;

    const unsigned int epochs_between_reports = 1000;


    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);

    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "xor.data", max_epochs,

        epochs_between_reports, desired_error);

    fann_save(ann, "xor_float.net");

    fann_destroy(ann);

//#####################################test##################################3

    fann_type *calc_out;

    fann_type input[3];

    struct fann *ann1 = fann_create_from_file("xor_float.net");

    input[0] = -1;

    input[1] = 1;

    input[2] = 1;

    calc_out = fann_run(ann1, input);

    printf("xor test (%f,%f,%f) -> %f\n", input[0], input[1], input[2], calc_out[0]);

    input[0] = -1;

    input[1] = -1;

    input[2] = 1;

    calc_out = fann_run(ann1, input);
    
    printf("xor test (%f,%f,%f) -> %f\n", input[0], input[1], input[2], calc_out[0]);

    fann_destroy(ann1);
   return 0;

}