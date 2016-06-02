#!/bin/bash

echo Installing first set of vm requirements
sudo pip install awscli
sudo yum install python-pip
sudo yum install git
git clone https://github.com/csking1/buddhism.git
sudo yum -y groupinstall "Development Tools"
sudo yum -y install fuse fuse-devel autoconf automake curl-devel libxml2-devel openssl-devel mailcap
wget https://github.com/s3fs-fuse/s3fs-fuse/archive/v1.78.tar.gz
tar xzf v1.78.tar.gz 
cd s3fs-fuse-1.78
./autogen.sh 
./configure 
make
sudo make install

echo Now you have to run this command "access-key-id:secret" > .passwd-s3fs
echo After that run start_two.sh
