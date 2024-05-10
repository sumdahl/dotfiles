#!/usr/bin/env bash
url="https://dl.pstmn.io/download/latest/linux_64"

echo "This is postman setup guide"

echo "Downloading postman"

wget -P ~/Downloads/ "$url"

echo "postman is successfully downloaded now setting up now extracting files"

tar -xzf "$url"

echo "Extracted, now removing previous version of postman"

sudo rm -rf /opt/Postman/

sudo mv Postman /opt/Postman

echo "File moved now creating a symbolic link"

sudo ln -s /opt/Postman/Postman /usr/bin/postman

echo "Now creating a desktop file, to launch from application launcher"

cat > ~/.local/share/applications/postman.desktop <<EOL
[Desktop Entry]
Encoding=UTF-8
Name=Postman
Exec=postman
# Before v6.1.2
# Icon=/opt/Postman/resources/app/assets/icon.png
Icon=/opt/Postman/app/resources/app/assets/icon.png
Terminal=false
Type=Application
Categories=Development;
EOL

echo "successfully setup, now you can remove file (optional)"

file="~/Downloads/$(url)"

read -p "Do you want to remove $file? (y/n): " answer

# Check user's response
case "$answer" in
    [yY]|[yY][eE][sS]) 
        # If user responds with y or yes, remove the file
        rm "$file"
        echo "File removed."
        ;;
    [nN]|[nN][oO])
        # If user responds with n or no, display a message and exit
        echo "File removal canceled."
        ;;
    *)
        # If user enters anything other than y or n, display an error message
        echo "Invalid response. Please enter y or n."
        ;;
esac


