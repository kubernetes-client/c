# Release Process

The Kubernetes C Client Project is released on an as-needed basis. The process is as follows:

## Request

An issue is proposing a new release with a changelog since the last release

All [OWNERS](OWNERS) must LGTM this release

## Prepare

Before release, we need to determine our release branch.

The release branch will always be of the form `release-<MAJOR>.<MINOR>`. Any
time a `<MAJOR>` or `<MINOR>` version number is incremented, a new release
branch needs to be created with `git checkout -b release-<MAJOR>.<MINOR>` _from
the branch containing the changes you want to release_. If you are only
releasing bug fixes for an existing `<MAJOR>.<MINOR>` release (a patch
release), you simply checkout that existing release branch `git checkout
release-<MAJOR>.<MINOR>`.

Now we are ready to perform the release.

## Release

There are 2 options to release: via GitHub Action or by manul

### Release via GitHub Action

Maintainers meeting the following requirements will be able to perform automated
release:

* Has "collaborator" permission or higher (otherwise they can't run the job manually).
* Should be in the OWNERS file.

#### Fill in the release workflow inputs manually

The GitHub Action workflow [Release](https://github.com/kubernetes-client/c/actions/workflows/release.yml) will require three manual inputs:

* The branch on which the workflow runs, must be a release branch, e.g. `release-X.Y`

* The releasing version, must be a valid semver `X.Y.Z` (without "v" prefix).

* Dry-Run: Indicating whether the release job will push the generated tag to the release branch and actually do a GitHub release.
  
Fill in the inputs, then click "Run" to start the job. 

#### Release note, announcements

After the release job successfully finishes, we're supposed to see a git tag `vX.Y.Z` pushed to the release branch, a GitHub draft release will also be packed on the tag.

In the end, manually update the release notes and publish the release on the GitHub release page.

### Release by manual

An OWNER runs `git tag -s $VERSION` or `git tag -a $VERSION` (If GPG-signed tag is not required) and inserts the changelog and pushes the tag with `git push origin $VERSION`

    e.g
    ```shell
    git tag -a v0.1.0 -m "version 0.1.0"
    git push origin v0.1.0
    ```

## Announcement

The release issue is closed

An announcement email is sent to `kubernetes-dev@googlegroups.com` with the subject `[ANNOUNCE] kubernetes-template-project $VERSION is released`
