import torch.nn as nn
import torch
import torchvision

my_model = torchvision.models.resnet101(pretrained=True)
my_model

for params in my_model.parameters():
  params.requires_grad=False

my_model.fc = nn.Sequential(nn.Linear(in_features=2048,out_features=100),
                            nn.ReLU(),
                            nn.Linear(in_features=100,out_features=32),
                            nn.ReLU(),
                            nn.Linear(in_features=32,out_features=2))
print(my_model)