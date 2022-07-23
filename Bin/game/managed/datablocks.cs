$managedDatablockSet = new SimSet() {
   canSaveDynamicFields = "1";
      setType = "Datablocks";

   new t2dImageMapDatablock(backgroundImageMap) {
      imageName = "~/data/images/background.png";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(ProcessedMapImageMap) {
      imageName = "~/data/images/ProcessedMap.png";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(teachingBuilding3ImageMap) {
      imageName = "~/data/images/teachingBuilding3.jpg";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(MapMarker1ImageMap) {
      imageName = "~/data/images/MapMarker1.png";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(playImageMap) {
      imageName = "~/data/images/play.png";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(musicImageMap) {
      imageName = "~/data/images/music.png";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(banaiImageMap1) {
      imageName = "~/data/images/banai.png";
      imageMode = "CELL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "0";
      preferPerf = "0";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "3";
      cellCountY = "3";
      cellWidth = "200";
      cellHeight = "200";
      preload = "0";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dAnimationDatablock(banaiAnimation) {
      imageMap = "banaiImageMap1";
      animationFrames = "4 3 2 1 0 5 6 7 8 7 6 5 0 1 2 3 4";
      animationTime = "1.13333";
      animationCycle = "1";
      randomStart = "0";
      startFrame = "0";
      animationPingPong = "0";
      animationReverse = "0";
   };
};
