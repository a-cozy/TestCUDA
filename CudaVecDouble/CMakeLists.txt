#find_package(CUDA REQUIRED)
#if(CUDA_FOUND)
#    message("Cuda version: " ${CUDA_VERSION})
#    CUDA_ADD_LIBRARY(CudaVecDouble STATIC
#        CudaVecDouble.cu
#        CudaVecDouble.h
#    )
#endif()

enable_language(CUDA)

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES 75)
endif()
 
ADD_LIBRARY(CudaVecDouble STATIC
        CudaVecDouble.cu
        CudaVecDouble.h
    )
