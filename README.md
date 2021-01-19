UNSW CPMSoc Website
===============
## File Layout

#### Page Files

All the page files are in `content` as markdown (md) or html files.

The file header looks like
```
---
title: "pagename"
menu: "main"
weight: 100
---
```
where title is the name of the page, menu should be main to tell it which navigation bar to attach to, weight is the order it appears in the navigation bar (lower means more left).

The rest of the file is pure markdown or html.

#### Javascript

If you need javascript, put it under `content/scripts` with a descriptive filename.

#### Page Assets

Any small assets such as images go under `content/assets`. Large files should be uploaded to a separate service such as Google Drive and the webpage should link to it.

#### Styles

Do not style HTML directly. Styling should be done through classes in `themes/cpmsoc/assets/sass`. Add an scss file and add the styles under a class. If you make a new file, import it in `main.scss`.

Bulma variables are contained in `variables.scss`. More information at (https://bulma.io/documentation/customize/variables/). This includes things such as background colour.

#### Default Styles

In `themes/cpmsoc/layouts/partials` are things like the footer, header and navbar item information.

#### Config

`config.toml` is the Hugo configuration file. More information at (https://gohugo.io/getting-started/configuration/).

## Testing Locally

1. Set up hugo (https://gohugo.io/getting-started/installing/). Probably easier to download the
release straight from GitHub. Use hugo-extended as we need support for scss compilation.
2. Download node.js (https://nodejs.org/en/) and also yarn (https://yarnpkg.com/).
3. Clone the project and cd into the directory.
4. Run `yarn` to install postcss-cli.
5. Run `hugo serve` to bring up a development server, which can be accessed at http://localhost:1313.

## Testing Remotely

1. Push onto your own branch.
2. Create a pull request to master.
3. A URL should be generated in the interface to a development deploy. You can update your own branch
as many times as you like and it will automatically rebuild to the same URL.
4. When you're happy, merge the pull request. Always do a "squash and merge" in order to declutter
the history. Also delete the branch once you're done.

## Notes

1. To make a dropdown item on the navigation bar, add
```
[menu]
  [[menu.main]]
  name = "dummy"
  weight = 5
```
to `config.toml` with the name and weight replaced with whatever is suitable. Create a folder in `content` with the name of the top level dropdown, and put markdown and html files into it.

Each file header should be
```
title: "dummy2"
menu:
  main:
    parent: "dummy"
    weight: 20
```
with the title being the page title, the parent being the name of the top level dropdown, and the weight being whatever is suitable.
