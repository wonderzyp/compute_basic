#!/bin/bash
# 删除目录下所有生成的exe文件
echo try to delete:

find -name '*.exe'
find -name '*.exe' -delete

echo successful delete