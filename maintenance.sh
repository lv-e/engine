#!/bin/bash

# say hello because it's polite
echo "hi! this is > lv engine < 's maintenance script"

publish(){

    while true; do

        if [[ `git status --porcelain` ]]; then
            echo "you do have local changes!"
            echo "will now commit and publish."
        else
            echo "you don't have local changes. do you really need a new version?"
            echo "anyway, will now add a tag and publish."
        fi
        
        read -p "it's that okay (y/n)? " yn; echo "--"

        case $yn in
            [Yy]* ) 

                echo "publishing a new tag (with path bump). what's the commit message?"
                read commit_message; echo "--"

                git add .
                VERSION=`git describe --tags --abbrev=0 | awk -F. '{$NF+=1; OFS="."; print $0}'`
                git tag -a $VERSION -m '$commit_message'
                git push origin $VERSION

                echo "there you go!"

                break;;
            [Nn]* )
                echo "ok! bye."
                exit;;
            * ) 
                echo "Please answer yes or no."
        esac
    done

}

runSandbox(){
    echo "Running make..."
    make -f sandbox/Makefile
    make -f sandbox/Makefile clean
    echo "Done! now will run game:"
    ./sandbox/game
}

## what should we do?

 while true; do

        echo "available options are:"
        echo " 1) publish a new version"
        echo " 2) run the sandbox app"

        read -p "choose one: " opt; echo "--"

        case $opt in
            1 ) publish; break;;
            2 ) runSandbox; break;;
            * ) echo "ok! bye."; exit;;
        esac
done