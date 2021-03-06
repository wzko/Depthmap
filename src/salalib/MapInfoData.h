// sala - a component of the Depthmap - spatial network analysis platform
// Copyright (C) 2000-2010 University College London, Alasdair Turner 

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __MAPINFODATA_H__
#define __MAPINFODATA_H__

// imported and exported data
// note: this is very basic and designed for axial line import / export only

// MapInfoData is stored with axial map data

class MapInfoData
{
friend class ShapeGraph;
friend class ShapeGraphs;
friend class ShapeMap;
   //
protected:
   pstring m_version;
   pstring m_charset;
   char m_delimiter;
   pstring m_index;
   pstring m_coordsys;
   pstring m_bounds;
   //
   // no longer use columnheads and table
   // -- where possible, added directly to the data
   // pvecstring m_columnheads; // <- original mapinfo column headers
   // pvecstring m_table;       // <- original mapinfo table (stored as a flat text file!)
   //
public:
   MapInfoData();
   // 
   int import(istream& miffile, istream& midfile, ShapeMap& map);
   //bool exportFile(ostream& miffile, ostream& midfile, const ShapeGraph& map);   // n.b., deprecated: use shapemap instead
   bool exportFile(ostream& miffile, ostream& midfile, const PointMap& points);
   bool exportFile(ostream& miffile, ostream& midfile, const ShapeMap& map);
   bool exportPolygons(ostream& miffile, ostream& midfile, const prefvec<pvecpoint>& polygons, const Region& region);
   //
   bool readheader(istream& miffile);
   bool readcolumnheaders(istream& miffile, istream& midfile, pvecstring& columnheads);
   void writeheader(ostream& miffile);
   void writetable(ostream& miffile, ostream& midfile, const AttributeTable& attributes);
   //
   istream& read(istream& stream, int version);
   ostream& write(ostream& stream);
};

#endif
