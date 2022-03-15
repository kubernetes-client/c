# How to regenerate the C client

## Regenerate with [kubernetes-client/gen](https://github.com/kubernetes-client/gen.git):

When a new version of kubernetes is released, you can follow the steps below to regenerate a new version of C client:

Fork and clone the `c` repository:

```bash
git clone https://github.com/your-name/c.git
git remote add upstream https://github.com/kubernetes-client/c.git
```

Clone the `gen` repository:

```bash
git clone https://github.com/kubernetes-client/gen.git
```

Prepare the below envronment variables:

```bash
CLIENT_REPO_ROOT=$HOME/c
GEN_REPO_ROOT=$HOME/gen
OUTPUT_DIR=$HOME/generated-kubernetes
SETTING_FILE=$CLIENT_REPO_ROOT/settings
NEW_BRANCH=your-branch-name
```

Create a new branch for the regenerated C client:

```bash
cd $CLIENT_REPO_ROOT
git checkout -b $NEW_BRANCH
```

Update the settings (e.g. version) for the new client in below file if needed:

```
$CLIENT_REPO_ROOT/settings
```

Delete the output directory if it already exists:
```bash
if [ -e $OUTPUT_DIR -a -d $OUTPUT_DIR ]; then rm -r $OUTPUT_DIR; fi
```

Execute the generating command:

```bash
cd $GEN_REPO_ROOT/openapi
./c.sh $OUTPUT_DIR $SETTING_FILE
```

Optionally, delete the old model/api/unit-test files in the C client because some of them are deprecated in the new Kubernetes spec:

```bash
cd $CLIENT_REPO_ROOT/kubernetes
find ./model -type f -not -name "int_or_string*" -exec rm -r {} \;
find ./api -type f -not -name "int_or_string*" -exec rm -r {} \;
find ./unit-test -type f -not -name "manual*" -exec rm -r {} \;
cd -
```

Copy the generated files to overwrite the files in the C client:

```bash
cp -rf $OUTPUT_DIR/* $CLIENT_REPO_ROOT/kubernetes/
```

Check the new/changed/deleted files:

```bash
cd $CLIENT_REPO_ROOT
git status
```

Build and test.

Commit the regnerate client to your repository:
```bash
cd $CLIENT_REPO_ROOT
git add .
git commit
git push origin $NEW_BRANCH
```

Create a Pull Request to merge your regenerated client to upstream repository.

## Regenerate with [openapi-generator](https://github.com/OpenAPITools/openapi-generator)

If you change the code ( e.g. C-libcurl [template](https://github.com/OpenAPITools/openapi-generator/tree/master/modules/openapi-generator/src/main/resources/C-libcurl) ) in [openapi-generator](https://github.com/OpenAPITools/openapi-generator), you can regenerate the client with the current [swagger.json](https://github.com/kubernetes-client/c/blob/master/kubernetes/swagger.json):

Execute the generating command in the directory of  `OpenAPITools/openapi-generator`

```bash
mvn -B --no-snapshot-updates clean package -DskipTests=true -Dmaven.javadoc.skip=true -Djacoco.skip=true

java -DdebugModels -DdebugOperations -jar modules/openapi-generator-cli/target/openapi-generator-cli.jar generate -i $CLIENT_REPO_ROOT/kubernetes/swagger.json -g c -o $OUTPUT_DIR --skip-validate-spec --type-mappings "int-or-string=IntOrString"
``` 

Copy the generated files to overwrite the files in the C client:

```bash
cp -rf $OUTPUT_DIR/* $CLIENT_REPO_ROOT/kubernetes/
```

And then follow the steps above to continue (build, test, commit and PR).