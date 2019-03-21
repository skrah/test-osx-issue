/*
 *  CXX=c++ python3 setup.py build develop
 *  Then python run.py
 */

#include <torch/extension.h>

class Cat {
 public:
  void cat(std::vector<torch::Tensor> tensors, int dim) {
    results_.push_back(torch::cat(tensors, dim));
  }

 private:
  std::vector<torch::Tensor> results_;
};

PYBIND11_MODULE(tensorbug, m) {
  py::class_<Cat>(m, "Cat").def(py::init<>()).def("cat", &Cat::cat);
}
