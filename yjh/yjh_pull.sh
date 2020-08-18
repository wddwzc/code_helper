git update-index --assume-unchanged .yjh/  #pull时候忽略xxx这个文件
#git update-index --no-assume-unchanged   .yjh/  #pull时候取消忽略xxx这个文件
git pull 
git status 
git checkout .
