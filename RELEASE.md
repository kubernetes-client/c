# Release Process

The Kubernetes C Client Project is released on an as-needed basis. The process is as follows:

1. An issue is proposing a new release with a changelog since the last release
1. All [OWNERS](OWNERS) must LGTM this release
1. An OWNER runs `git tag -s $VERSION` or `git tag -a $VERSION` (If GPG-signed tag is not required) and inserts the changelog and pushes the tag with `git push $VERSION`

    e.g
    ```shell
    git tag -a v0.1.0 -m "version 0.1.0"
    ```

1. The release issue is closed
1. An announcement email is sent to `kubernetes-dev@googlegroups.com` with the subject `[ANNOUNCE] kubernetes-template-project $VERSION is released`
