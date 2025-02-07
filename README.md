UNSW CPMSoc Website
===================

We use the static site generator [Hugo](https://gohugo.io/documentation/).

## Testing Locally

1. Set up Hugo (https://gohugo.io/getting-started/installing/). Probably easier to download the
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

## File Layout Primer

#### Page Files

All the page files are in `content` as markdown (md) or html files.

The file starts with some page metadata in yaml.

For example, in
```
---
title: "Home"
menu: "main"
weight: 1
---
```
`title` is the page title, `menu` is the navigation bar to attach the page to, and `weight` positions the page in the navigation bar.

The rest of the file is pure markdown or html.

#### Page Assets

Assets such as images specific to a particular page are best to attach using [page bundles](https://gohugo.io/content-management/page-bundles/), like is done in `content/sponsors`. Alternatively, they can go under `static/assets`, though this is best reserved for assets used by more than one page. Large files should perhaps be uploaded to a separate service such as Google Drive and then linked to.

#### Layouts

The main beauty of Hugo is in its layout system.
Roughly, this is how page content is automatically generated so you don't copy and paste html everywhere.
Here are some ways we use it for this project. Files are in `themes/cpmsoc/layouts`.

- Partials: repeated elements like the footer, header and navbar system
- Competitions: competitions list page is fully generated from the metadata in the individual competition pages

#### Config

`config.toml` is the Hugo configuration file. More information at (https://gohugo.io/getting-started/configuration/).
