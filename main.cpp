#include<vector>
#include<iostream>
#include<fstream>
#include"file_utils.hpp"
#include"segmentation.hpp"
#include"timer.hpp"
#include"djs.hpp"



int main(int argc, char** argv)
{
    int dim0, dim1;
    dim0 = atoi(argv[1]);
    dim1 = atoi(argv[2]);
    float eb = atof(argv[4]);
    int dims[2] = {dim0, dim1};
    int num_elements = dim0 * dim1;
    std::vector<float> data(num_elements);
    readfile(argv[3], num_elements, data.data());

    // build the segmentation object 
    Posterization<float> posterization(data.data(), 2, dims);
    Timer timer(true);


    std::vector<int> segmentation_map = posterization.get_segmentation_map(eb);
    timer.stop("Segmentation time");

    // write the segmentation map to a file
    writefile("segmentation_map.dat", segmentation_map.data(), segmentation_map.size());

}