import torch
import tensorbug

catter = tensorbug.Cat()
catter.cat([torch.zeros(1)], 10)
