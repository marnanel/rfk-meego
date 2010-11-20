#!/bin/bash

# make the SOURCES tarball
mkdir /tmp/$$
mkdir /tmp/$$/rfk-2.0.0/
cp -r * /tmp/$$/rfk-2.0.0/
pushd /tmp/$$/
tar cjf rfk-2.0.0.tar.bz2 rfk-2.0.0/
mv rfk-2.0.0.tar.bz2 ~/rpmbuild/SOURCES/
popd
rm -rf /tmp/$$/rfk-2.0.0/
# now make the spec
specify rfk.yaml
cp rfk.yaml ~/rpmbuild/SOURCES/
cp rfk.spec ~/rpmbuild/SPECS/
pushd ~/rpmbuild/SPECS/
# now kick it all off
rpmbuild -ba rfk.spec

