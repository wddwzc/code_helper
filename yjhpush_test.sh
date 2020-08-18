#!/bin/bash
git add .
git commit -m 'update'
git push -u origin master
ssh root@推送的服务器IP <<EOF
cd /usr/blog
sh ./update_blog.sh
exit
EOF
