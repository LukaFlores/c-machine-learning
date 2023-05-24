#include <stdio.h>
#include <stdlib.h>
#include <time.h>



float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8}
};

#define train_count (sizeof(train) / sizeof(train[0]))



float rand_float(void) {
    return (float) rand() / (float) RAND_MAX;
}


// Cost or Loss Function
// Measure the cost or loss of the model (Does it perform well?) 
// The closer the cost is to 0 the better the model behaves on the training data
float cost(float w){
    float result = 0.0f;
    for(size_t i = 0; i < train_count; i++){
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}



int main(){
    //srand(time(0));
    srand(12);

    float w = rand_float() * 10.0f;

    // Cost Function 
    float eps = 1e-3;
    float rate = 1e-3;

    for (size_t i = 0; i < 500; ++i) {
        float dcost = (cost(w + eps) - cost(w))/eps;
        w -= rate*dcost;
        printf("Cost: %f, w = %f \n", cost(w), w);
    }

    printf("w: %f \n", w);
    return 0;
}


