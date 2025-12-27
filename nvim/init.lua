-- Load Lazy plugin manager
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  print("lazy.nvim not found")
  return
end

vim.opt.rtp:prepend(lazypath)
vim.wo.number = true
vim.wo.relativenumber = true
require("lazy").setup({
  {
    "catppuccin/nvim", -- set theme
    name = "catppuccin",
    priority = 1000,
    config = function()
      require("catppuccin").setup({
        flavour = "mocha", -- latte, frappe, macchiato, mocha
        transparent_background = false,
      })
      vim.cmd.colorscheme "catppuccin"
    end,
  },
})
