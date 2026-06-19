#!/bin/bash

# Internal Command Functions
ll() {
  ls -l
}

makedir() {
  read -p "Enter folder name to create: " folder_name
  if [ -d "$folder_name" ]; then
    echo "Directory '$folder_name' already exists."
  else
    mkdir "$folder_name"
    echo "Directory '$folder_name' created."
  fi
}

remove() {
  read -p "Enter the file name to remove: " filename
  rm -i "$filename"
}

copyit() {
  read -p "Enter source file name: " src
  read -p "Enter destination file name: " dest
  cp "$src" "$dest"
  echo "File copied from $src to $dest."
}

moveit() {
  read -p "Enter file name to move: " file
  read -p "Enter destination folder: " folder
  mv "$file" "$folder/"
  echo "Moved $file to $folder/"
}

catfile() {
  read -p "Enter file name to display: " file
  cat "$file"
}

# Simulated USB Mount/Unmount for Git Bash
mount_usb() {
  read -p "Enter the USB drive letter (e.g., E): " drive_letter
  echo "Simulating mount of drive $drive_letter..."
  echo "Drive $drive_letter mounted at /mnt/$drive_letter (simulated)."
}

unmount_usb() {
  read -p "Enter the USB drive letter to unmount (e.g., E): " drive_letter
  echo "Simulating unmount of drive $drive_letter..."
  echo "Drive $drive_letter unmounted (simulated)."
}

# Main menu loop
while true; do
  echo ""
  echo "====== Command Menu ======"
  echo "Internal Commands:"
  echo " 1. ll        -> List files (ls -l)"
  echo " 2. makedir   -> Make directory"
  echo " 3. remove    -> Remove file interactively"
  echo " 4. copyit    -> Copy file"
  echo " 5. moveit    -> Move file"
  echo ""
  echo "External Commands:"
  echo " 6. catfile   -> View file contents"
  echo " 7. mount     -> Simulate mount USB drive"
  echo " 8. unmount   -> Simulate unmount USB drive"
  echo " 9. date      -> Show date"
  echo "10. uptime    -> Show system uptime"
  echo "11. exit      -> Exit script"
  echo "==========================="
  read -p "Enter your choice (1-11): " choice
  case $choice in
    1) ll ;;
    2) makedir ;;
    3) remove ;;
    4) copyit ;;
    5) moveit ;;
    6) catfile ;;
    7) mount_usb ;;
    8) unmount_usb ;;
    9) date ;;
    10) uptime ;;
    11) echo "Exiting..."; break ;;
    *) echo "Invalid choice. Please try again." ;;
  esac
done
