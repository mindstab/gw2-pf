/*
MIT License

Copyright (c) 2023 mindstab <zeropolyz@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <cstdint>

namespace pf {
namespace details {

template <size_t N>
[[nodiscard]] consteval uint32_t Magic(const char (&code)[N]) noexcept(true) {
  uint32_t value = 0;
  if constexpr (N >= 4) {
    value |= code[3] << 24;
  }
  if constexpr (N >= 3) {
    value |= code[2] << 16;
  }
  if constexpr (N >= 2) {
    value |= code[1] << 8;
  }
  if constexpr (N >= 1) {
    value |= code[0];
  }

  return value;
}

}  // namespace details

enum class FourCC : uint32_t {
  ABIX = details::Magic("ABIX"),
  ABNK = details::Magic("ABNK"),
  AMAT = details::Magic("AMAT"),
  AMSP = details::Magic("AMSP"),
  ANIM = details::Magic("ANIM"),
  ARMF = details::Magic("ARMF"),
  ASND = details::Magic("ASND"),
  BGFX = details::Magic("BGFX"),
  BIDX = details::Magic("BIDX"),
  BKCK = details::Magic("BKCK"),
  CINP = details::Magic("CINP"),
  COLL = details::Magic("COLL"),
  CSCN = details::Magic("CSCN"),
  CDHS = details::Magic("CDHS"),
  DX9S = details::Magic("DX9S"),
  EXPA = details::Magic("EXPA"),
  GAME = details::Magic("GAME"),
  GEOM = details::Magic("GEOM"),
  GR2S = details::Magic("GR2S"),
  GRMT = details::Magic("GRMT"),
  ICON = details::Magic("ICON"),
  MFST = details::Magic("MFST"),
  MODL = details::Magic("MODL"),
  Main = details::Magic("Main"),
  PGTB = details::Magic("PGTB"),
  PIMG = details::Magic("PIMG"),
  PRPS = details::Magic("PRPS"),
  ROOT = details::Magic("ROOT"),
  SKEL = details::Magic("SKEL"),
  TOOL = details::Magic("TOOL"),
  acct = details::Magic("acct"),
  anic = details::Magic("anic"),
  anim = details::Magic("anim"),
  area = details::Magic("area"),
  audi = details::Magic("audi"),
  audo = details::Magic("audo"),
  bloc = details::Magic("bloc"),
  cg15 = details::Magic("cg15"),
  chat = details::Magic("chat"),
  char_ = details::Magic("char"),
  cmaC = details::Magic("cmaC"),
  cmpc = details::Magic("cmpc"),
  cnfg = details::Magic("cnfg"),
  cntc = details::Magic("cntc"),
  comm = details::Magic("comm"),
  comp = details::Magic("comp"),
  core = details::Magic("core"),
  cube = details::Magic("cube"),
  dcal = details::Magic("dcal"),
  dlog = details::Magic("dlog"),
  edit = details::Magic("edit"),
  emoc = details::Magic("emoc"),
  env = details::Magic("env"),
  eula = details::Magic("eula"),
  exp = details::Magic("exp"),
  fall = details::Magic("fall"),
  grfx = details::Magic("grfx"),
  gusu = details::Magic("gusu"),
  havk = details::Magic("havk"),
  inpt = details::Magic("inpt"),
  laye = details::Magic("laye"),
  lght = details::Magic("lght"),
  locl = details::Magic("locl"),
  mach = details::Magic("mach"),
  main = details::Magic("main"),
  mapc = details::Magic("mapc"),
  mfst = details::Magic("mfst"),
  msn = details::Magic("msn"),
  nm15 = details::Magic("nm15"),
  nmex = details::Magic("nmex"),
  noti = details::Magic("noti"),
  obs = details::Magic("obs"),
  occ = details::Magic("occ"),
  octm = details::Magic("octm"),
  parm = details::Magic("parm"),
  pex = details::Magic("pex"),
  phys = details::Magic("phys"),
  plrs = details::Magic("plrs"),
  pnvm = details::Magic("pnvm"),
  prlt = details::Magic("prlt"),
  prp2 = details::Magic("prp2"),
  pvpl = details::Magic("pvpl"),
  reso = details::Magic("reso"),
  rive = details::Magic("rive"),
  seqn = details::Magic("seqn"),
  shad = details::Magic("shad"),
  shex = details::Magic("shex"),
  shor = details::Magic("shor"),
  snd = details::Magic("snd"),
  sqwd = details::Magic("sqwd"),
  surf = details::Magic("surf"),
  tlfs = details::Magic("tlfs"),
  trn = details::Magic("trn"),
  trni = details::Magic("trni"),
  txtV = details::Magic("txtV"),
  txtm = details::Magic("txtm"),
  txtv = details::Magic("txtv"),
  umap = details::Magic("umap"),
  uxac = details::Magic("uxac"),
  uxch = details::Magic("uxch"),
  uxlc = details::Magic("uxlc"),
  vari = details::Magic("vari"),
  watr = details::Magic("watr"),
  zon2 = details::Magic("zon2"),
  DATA = details::Magic("DATA"),
  mMet = details::Magic("mMet"),
  hvkC = details::Magic("hvkC"),
  mpsd = details::Magic("mpsd"),
};

}  // namespace pf
