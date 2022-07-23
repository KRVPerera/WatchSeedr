## View

List contents of root folder in JSON

    curl -X GET -u "email:password" https://www.seedr.cc/rest/folder

List contents of folder by ID in JSON

    curl -X GET -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}

## Downloads

Download folder as ZIP file (make sure to follow redirects)

    curl -o filename.zip -L -X GET -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}/download

Download file

    curl -o -L -X GET -u "email:password" https://www.seedr.cc/rest/file/{file_id}

Get HLS converted video

    curl -o -L -X GET -u "email:password" https://www.seedr.cc/rest/file/{file_id}/hls


## Thumbnails

Get File Image ( if exists )

    curl -o -L -X GET -u "email:password" https://www.seedr.cc/rest/file/{file_id}/image

Get File Thumbnail 32px * relative height ( if exists )

    curl -o -L -X GET -u "email:password" https://www.seedr.cc/rest/file/{file_id}/thumbnail

Get File Preview Image

    curl -o -L -X GET -u "email:password" https://www.seedr.cc/rest/file/{file_id}/image


## Get User Data

    curl -X GET -u "email:password" https://www.seedr.cc/rest/user


## Transfers

### Get Transfer Data
    
    curl -X GET -u "email:password" https://www.seedr.cc/rest/transfer/{id}

### Adding Transfers

Magnet

    curl -X POST --data "magnet={magnet_link}" -u "email:password" https://www.seedr.cc/rest/transfer/magnet

URL

    curl -X POST --data "url={url}" -u "email:password" https://www.seedr.cc/rest/transfer/url

Local File

    curl -X POST -F "file=@full_path_to_file" -u "email:password" https://www.seedr.cc/rest/transfer/file

## Folders

List contents of folder by ID in JSON

    curl -X GET -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}

List contents of root folder in JSON

    curl -X GET -u "email:password" https://www.seedr.cc/rest/folder

Create folder

    curl -X POST -u "email:password" https://www.seedr.cc/rest/folder

Rename folder

    curl -X POST -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}/rename

Delete folder

    curl -X POST -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}/delete

## Rename

Rename file

    curl -X POST -u "email:password" https://www.seedr.cc/rest/file/{file_id}/rename

Rename folder

    curl -X POST -u "email:password" https://www.seedr.cc/rest/folder/{folder_id}/rename