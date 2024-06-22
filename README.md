# Armazen

![GitHub Issues or Pull Requests](https://img.shields.io/github/issues-pr/roqueando/league-of-data)

![armazen_logo](/images/armazen.png)

> Armazen is a database for logs, that uses Drain algorithm for structuring logs and a variation of gzip tree for compression. 

### updates and improvements

The project still in development and the next updates will be coded in the following tasks:
- [ ] build a simple CLI to insert logs
- [ ] build the parser tree for structuring logs
- [ ] build the compression tree to store logs
- [ ] build the query language

## 💻 pre-requisites

Before start, verify if you have the following things installed:
- gcc or clang
- cmake

## 🚀 installing

For install from source, first you need:

- clone repository
```sh
git clone https://github.com/roqueando/armazen.git
```

- run build step
```sh
make build
```

- run tests
```sh
make test
```

## ☕using
This project will be a CLI and further a server, but for now you only have to run with `make`

```sh
make run
```

## 😄 be a contributor
Want to be part of contributor? See the [contributing](CONTRIBUTING.md) page for how to contribute.

## 📝 license

This project is under the license. See the file [LICENSE](LICENSE.md) for more details
